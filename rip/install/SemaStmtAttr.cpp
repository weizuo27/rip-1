//===--- SemaStmtAttr.cpp - Statement Attribute Handling ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//  This file implements stmt-related attribute processing.
//
//===----------------------------------------------------------------------===//

#include "clang/Sema/SemaInternal.h"
#include "clang/AST/ASTContext.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Sema/DelayedDiagnostic.h"
#include "clang/Sema/Lookup.h"
#include "clang/Sema/LoopHint.h"
#include "clang/Sema/ScopeInfo.h"
#include "llvm/ADT/StringExtras.h"

using namespace clang;
using namespace sema;

static Attr *handleFallThroughAttr(Sema &S, Stmt *St, const AttributeList &A,
                                   SourceRange Range) {
  FallThroughAttr Attr(A.getRange(), S.Context,
                       A.getAttributeSpellingListIndex());
  if (!isa<NullStmt>(St)) {
    S.Diag(A.getRange().getBegin(), diag::err_fallthrough_attr_wrong_target)
        << Attr.getSpelling() << St->getLocStart();
    if (isa<SwitchCase>(St)) {
      SourceLocation L = S.getLocForEndOfToken(Range.getEnd());
      S.Diag(L, diag::note_fallthrough_insert_semi_fixit)
          << FixItHint::CreateInsertion(L, ";");
    }
    return nullptr;
  }
  auto *FnScope = S.getCurFunction();
  if (FnScope->SwitchStack.empty()) {
    S.Diag(A.getRange().getBegin(), diag::err_fallthrough_attr_outside_switch);
    return nullptr;
  }

  // If this is spelled as the standard C++1z attribute, but not in C++1z, warn
  // about using it as an extension.
  if (!S.getLangOpts().CPlusPlus1z && A.isCXX11Attribute() &&
      !A.getScopeName())
    S.Diag(A.getLoc(), diag::ext_cxx1z_attr) << A.getName();

  FnScope->setHasFallthroughStmt();
  return ::new (S.Context) auto(Attr);
}

static Attr *handleLoopHintAttr(Sema &S, Stmt *St, const AttributeList &A,
                                SourceRange) {
  IdentifierLoc *PragmaNameLoc = A.getArgAsIdent(0);
  IdentifierLoc *OptionLoc = A.getArgAsIdent(1);
  IdentifierLoc *StateLoc = A.getArgAsIdent(2);
  Expr *ValueExpr = A.getArgAsExpr(3);

  bool PragmaUnroll = PragmaNameLoc->Ident->getName() == "unroll";
  bool PragmaNoUnroll = PragmaNameLoc->Ident->getName() == "nounroll";
  if (St->getStmtClass() != Stmt::DoStmtClass &&
      St->getStmtClass() != Stmt::ForStmtClass &&
      St->getStmtClass() != Stmt::CXXForRangeStmtClass &&
      St->getStmtClass() != Stmt::WhileStmtClass) {
    const char *Pragma =
        llvm::StringSwitch<const char *>(PragmaNameLoc->Ident->getName())
            .Case("unroll", "#pragma unroll")
            .Case("nounroll", "#pragma nounroll")
            .Default("#pragma clang loop");
    S.Diag(St->getLocStart(), diag::err_pragma_loop_precedes_nonloop) << Pragma;
    return nullptr;
  }

  LoopHintAttr::Spelling Spelling;
  LoopHintAttr::OptionType Option;
  LoopHintAttr::LoopHintState State;
  if (PragmaNoUnroll) {
    // #pragma nounroll
    Spelling = LoopHintAttr::Pragma_nounroll;
    Option = LoopHintAttr::Unroll;
    State = LoopHintAttr::Disable;
  } else if (PragmaUnroll) {
    Spelling = LoopHintAttr::Pragma_unroll;
    if (ValueExpr) {
      // #pragma unroll N
      Option = LoopHintAttr::UnrollCount;
      State = LoopHintAttr::Numeric;
    } else {
      // #pragma unroll
      Option = LoopHintAttr::Unroll;
      State = LoopHintAttr::Enable;
    }
  } else {
    // #pragma clang loop ...
    Spelling = LoopHintAttr::Pragma_clang_loop;
    assert(OptionLoc && OptionLoc->Ident &&
           "Attribute must have valid option info.");
    Option = llvm::StringSwitch<LoopHintAttr::OptionType>(
                 OptionLoc->Ident->getName())
                 .Case("vectorize", LoopHintAttr::Vectorize)
                 .Case("vectorize_width", LoopHintAttr::VectorizeWidth)
                 .Case("interleave", LoopHintAttr::Interleave)
                 .Case("interleave_count", LoopHintAttr::InterleaveCount)
                 .Case("unroll", LoopHintAttr::Unroll)
                 .Case("unroll_count", LoopHintAttr::UnrollCount)
                 .Case("critical", LoopHintAttr::IsCritical)
                 .Case("distribute", LoopHintAttr::Distribute)
                 .Default(LoopHintAttr::Vectorize);
    if (Option == LoopHintAttr::VectorizeWidth ||
        Option == LoopHintAttr::InterleaveCount ||
        Option == LoopHintAttr::UnrollCount) {
      assert(ValueExpr && "Attribute must have a valid value expression.");
      if (S.CheckLoopHintExpr(ValueExpr, St->getLocStart()))
        return nullptr;
      State = LoopHintAttr::Numeric;
    } else if (Option == LoopHintAttr::Vectorize ||
               Option == LoopHintAttr::Interleave ||
               Option == LoopHintAttr::IsCritical ||
               Option == LoopHintAttr::Unroll ||
               Option == LoopHintAttr::Distribute) {
      assert(StateLoc && StateLoc->Ident && "Loop hint must have an argument");
      if (StateLoc->Ident->isStr("disable"))
        State = LoopHintAttr::Disable;
      else if (StateLoc->Ident->isStr("assume_safety"))
        State = LoopHintAttr::AssumeSafety;
      else if (StateLoc->Ident->isStr("full"))
        State = LoopHintAttr::Full;
      else if (StateLoc->Ident->isStr("enable"))
        State = LoopHintAttr::Enable;
      else
        llvm_unreachable("bad loop hint argument");
    } else
      llvm_unreachable("bad loop hint");
  }

  return LoopHintAttr::CreateImplicit(S.Context, Spelling, Option, State,
                                      ValueExpr, A.getRange());
}

static void
CheckForIncompatibleAttributes(Sema &S,
                               const SmallVectorImpl<const Attr *> &Attrs) {
  // There are 4 categories of loop hints attributes: vectorize, interleave,
  // unroll and distribute. Except for distribute they come in two variants: a
  // state form and a numeric form.  The state form selectively
  // defaults/enables/disables the transformation for the loop (for unroll,
  // default indicates full unrolling rather than enabling the transformation).
  // The numeric form form provides an integer hint (for example, unroll count)
  // to the transformer. The following array accumulates the hints encountered
  // while iterating through the attributes to check for compatibility.
  struct {
    const LoopHintAttr *StateAttr;
    const LoopHintAttr *NumericAttr;
  } HintAttrs[] = {{nullptr, nullptr},
                   {nullptr, nullptr},
                   {nullptr, nullptr},
                   {nullptr, nullptr}};

  for (const auto *I : Attrs) {
    const LoopHintAttr *LH = dyn_cast<LoopHintAttr>(I);

    // Skip non loop hint attributes
    if (!LH)
      continue;

    LoopHintAttr::OptionType Option = LH->getOption();
    enum { Vectorize, Interleave, Unroll, Distribute } Category;
    switch (Option) {
    case LoopHintAttr::Vectorize:
    case LoopHintAttr::VectorizeWidth:
    case LoopHintAttr::IsCritical:
      Category = Vectorize;
      break;
    case LoopHintAttr::Interleave:
    case LoopHintAttr::InterleaveCount:
      Category = Interleave;
      break;
    case LoopHintAttr::Unroll:
    case LoopHintAttr::UnrollCount:
      Category = Unroll;
      break;
    case LoopHintAttr::Distribute:
      // Perform the check for duplicated 'distribute' hints.
      Category = Distribute;
      break;
    };

    auto &CategoryState = HintAttrs[Category];
    const LoopHintAttr *PrevAttr;
    if (Option == LoopHintAttr::Vectorize ||
        Option == LoopHintAttr::Interleave || Option == LoopHintAttr::Unroll || Option == LoopHintAttr::IsCritical ||
        Option == LoopHintAttr::Distribute) {
      // Enable|Disable|AssumeSafety hint.  For example, vectorize(enable).
      PrevAttr = CategoryState.StateAttr;
      CategoryState.StateAttr = LH;
    } else {
      // Numeric hint.  For example, vectorize_width(8).
      PrevAttr = CategoryState.NumericAttr;
      CategoryState.NumericAttr = LH;
    }

    PrintingPolicy Policy(S.Context.getLangOpts());
    SourceLocation OptionLoc = LH->getRange().getBegin();
    if (PrevAttr)
      // Cannot specify same type of attribute twice.
      S.Diag(OptionLoc, diag::err_pragma_loop_compatibility)
          << /*Duplicate=*/true << PrevAttr->getDiagnosticName(Policy)
          << LH->getDiagnosticName(Policy);

    if (CategoryState.StateAttr && CategoryState.NumericAttr &&
        (Category == Unroll ||
         CategoryState.StateAttr->getState() == LoopHintAttr::Disable)) {
      // Disable hints are not compatible with numeric hints of the same
      // category.  As a special case, numeric unroll hints are also not
      // compatible with enable or full form of the unroll pragma because these
      // directives indicate full unrolling.
      S.Diag(OptionLoc, diag::err_pragma_loop_compatibility)
          << /*Duplicate=*/false
          << CategoryState.StateAttr->getDiagnosticName(Policy)
          << CategoryState.NumericAttr->getDiagnosticName(Policy);
    }
  }
}

static Attr *handleOpenCLUnrollHint(Sema &S, Stmt *St, const AttributeList &A,
                                    SourceRange Range) {
  // OpenCL v2.0 s6.11.5 - opencl_unroll_hint can have 0 arguments (compiler
  // determines unrolling factor) or 1 argument (the unroll factor provided
  // by the user).

  if (S.getLangOpts().OpenCLVersion < 200) {
    S.Diag(A.getLoc(), diag::err_attribute_requires_opencl_version)
        << A.getName() << "2.0" << 1;
    return nullptr;
  }

  unsigned NumArgs = A.getNumArgs();

  if (NumArgs > 1) {
    S.Diag(A.getLoc(), diag::err_attribute_too_many_arguments) << A.getName()
                                                               << 1;
    return nullptr;
  }

  unsigned UnrollFactor = 0;

  if (NumArgs == 1) {
    Expr *E = A.getArgAsExpr(0);
    llvm::APSInt ArgVal(32);

    if (!E->isIntegerConstantExpr(ArgVal, S.Context)) {
      S.Diag(A.getLoc(), diag::err_attribute_argument_type)
          << A.getName() << AANT_ArgumentIntegerConstant << E->getSourceRange();
      return nullptr;
    }

    int Val = ArgVal.getSExtValue();

    if (Val <= 0) {
      S.Diag(A.getRange().getBegin(),
             diag::err_attribute_requires_positive_integer)
          << A.getName();
      return nullptr;
    }
    UnrollFactor = Val;
  }

  return OpenCLUnrollHintAttr::CreateImplicit(S.Context, UnrollFactor);
}

static Attr *ProcessStmtAttribute(Sema &S, Stmt *St, const AttributeList &A,
                                  SourceRange Range) {
  switch (A.getKind()) {
  case AttributeList::UnknownAttribute:
    S.Diag(A.getLoc(), A.isDeclspecAttribute() ?
           diag::warn_unhandled_ms_attribute_ignored :
           diag::warn_unknown_attribute_ignored) << A.getName();
    return nullptr;
  case AttributeList::AT_FallThrough:
    return handleFallThroughAttr(S, St, A, Range);
  case AttributeList::AT_LoopHint:
    return handleLoopHintAttr(S, St, A, Range);
  case AttributeList::AT_OpenCLUnrollHint:
    return handleOpenCLUnrollHint(S, St, A, Range);
  default:
    // if we're here, then we parsed a known attribute, but didn't recognize
    // it as a statement attribute => it is declaration attribute
    S.Diag(A.getRange().getBegin(), diag::err_decl_attribute_invalid_on_stmt)
        << A.getName() << St->getLocStart();
    return nullptr;
  }
}

StmtResult Sema::ProcessStmtAttributes(Stmt *S, AttributeList *AttrList,
                                       SourceRange Range) {
  SmallVector<const Attr*, 8> Attrs;
  for (const AttributeList* l = AttrList; l; l = l->getNext()) {
    if (Attr *a = ProcessStmtAttribute(*this, S, *l, Range))
      Attrs.push_back(a);
  }

  CheckForIncompatibleAttributes(*this, Attrs);

  if (Attrs.empty())
    return S;

  return ActOnAttributedStmt(Range.getBegin(), Attrs, S);
}
