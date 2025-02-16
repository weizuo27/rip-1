# This file was automatically generated by SWIG (http://www.swig.org).
# Version 3.0.8
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.





from sys import version_info
if version_info >= (2, 6, 0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_enum_OpClass', [dirname(__file__)])
        except ImportError:
            import _enum_OpClass
            return _enum_OpClass
        if fp is not None:
            try:
                _mod = imp.load_module('_enum_OpClass', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _enum_OpClass = swig_import_helper()
    del swig_import_helper
else:
    import _enum_OpClass
del version_info
try:
    _swig_property = property
except NameError:
    pass  # Python < 2.2 doesn't have 'property'.


def _swig_setattr_nondynamic(self, class_type, name, value, static=1):
    if (name == "thisown"):
        return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name, None)
    if method:
        return method(self, value)
    if (not static):
        object.__setattr__(self, name, value)
    else:
        raise AttributeError("You cannot add attributes to %s" % self)


def _swig_setattr(self, class_type, name, value):
    return _swig_setattr_nondynamic(self, class_type, name, value, 0)


def _swig_getattr_nondynamic(self, class_type, name, static=1):
    if (name == "thisown"):
        return self.this.own()
    method = class_type.__swig_getmethods__.get(name, None)
    if method:
        return method(self)
    if (not static):
        return object.__getattr__(self, name)
    else:
        raise AttributeError(name)

def _swig_getattr(self, class_type, name):
    return _swig_getattr_nondynamic(self, class_type, name, 0)


def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object:
        pass
    _newclass = 0



def _swig_setattr_nondynamic_method(set):
    def set_attr(self, name, value):
        if (name == "thisown"):
            return self.this.own(value)
        if hasattr(self, name) or (name == "this"):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add attributes to %s" % self)
    return set_attr



_enum_OpClass.No_OpClass_swigconstant(_enum_OpClass)
No_OpClass = _enum_OpClass.No_OpClass

_enum_OpClass.IntAlu_swigconstant(_enum_OpClass)
IntAlu = _enum_OpClass.IntAlu

_enum_OpClass.IntMult_swigconstant(_enum_OpClass)
IntMult = _enum_OpClass.IntMult

_enum_OpClass.IntDiv_swigconstant(_enum_OpClass)
IntDiv = _enum_OpClass.IntDiv

_enum_OpClass.FloatAdd_swigconstant(_enum_OpClass)
FloatAdd = _enum_OpClass.FloatAdd

_enum_OpClass.FloatCmp_swigconstant(_enum_OpClass)
FloatCmp = _enum_OpClass.FloatCmp

_enum_OpClass.FloatCvt_swigconstant(_enum_OpClass)
FloatCvt = _enum_OpClass.FloatCvt

_enum_OpClass.FloatMult_swigconstant(_enum_OpClass)
FloatMult = _enum_OpClass.FloatMult

_enum_OpClass.FloatDiv_swigconstant(_enum_OpClass)
FloatDiv = _enum_OpClass.FloatDiv

_enum_OpClass.FloatSqrt_swigconstant(_enum_OpClass)
FloatSqrt = _enum_OpClass.FloatSqrt

_enum_OpClass.SimdAdd_swigconstant(_enum_OpClass)
SimdAdd = _enum_OpClass.SimdAdd

_enum_OpClass.SimdAddAcc_swigconstant(_enum_OpClass)
SimdAddAcc = _enum_OpClass.SimdAddAcc

_enum_OpClass.SimdAlu_swigconstant(_enum_OpClass)
SimdAlu = _enum_OpClass.SimdAlu

_enum_OpClass.SimdCmp_swigconstant(_enum_OpClass)
SimdCmp = _enum_OpClass.SimdCmp

_enum_OpClass.SimdCvt_swigconstant(_enum_OpClass)
SimdCvt = _enum_OpClass.SimdCvt

_enum_OpClass.SimdMisc_swigconstant(_enum_OpClass)
SimdMisc = _enum_OpClass.SimdMisc

_enum_OpClass.SimdMult_swigconstant(_enum_OpClass)
SimdMult = _enum_OpClass.SimdMult

_enum_OpClass.SimdMultAcc_swigconstant(_enum_OpClass)
SimdMultAcc = _enum_OpClass.SimdMultAcc

_enum_OpClass.SimdShift_swigconstant(_enum_OpClass)
SimdShift = _enum_OpClass.SimdShift

_enum_OpClass.SimdShiftAcc_swigconstant(_enum_OpClass)
SimdShiftAcc = _enum_OpClass.SimdShiftAcc

_enum_OpClass.SimdSqrt_swigconstant(_enum_OpClass)
SimdSqrt = _enum_OpClass.SimdSqrt

_enum_OpClass.SimdFloatAdd_swigconstant(_enum_OpClass)
SimdFloatAdd = _enum_OpClass.SimdFloatAdd

_enum_OpClass.SimdFloatAlu_swigconstant(_enum_OpClass)
SimdFloatAlu = _enum_OpClass.SimdFloatAlu

_enum_OpClass.SimdFloatCmp_swigconstant(_enum_OpClass)
SimdFloatCmp = _enum_OpClass.SimdFloatCmp

_enum_OpClass.SimdFloatCvt_swigconstant(_enum_OpClass)
SimdFloatCvt = _enum_OpClass.SimdFloatCvt

_enum_OpClass.SimdFloatDiv_swigconstant(_enum_OpClass)
SimdFloatDiv = _enum_OpClass.SimdFloatDiv

_enum_OpClass.SimdFloatMisc_swigconstant(_enum_OpClass)
SimdFloatMisc = _enum_OpClass.SimdFloatMisc

_enum_OpClass.SimdFloatMult_swigconstant(_enum_OpClass)
SimdFloatMult = _enum_OpClass.SimdFloatMult

_enum_OpClass.SimdFloatMultAcc_swigconstant(_enum_OpClass)
SimdFloatMultAcc = _enum_OpClass.SimdFloatMultAcc

_enum_OpClass.SimdFloatSqrt_swigconstant(_enum_OpClass)
SimdFloatSqrt = _enum_OpClass.SimdFloatSqrt

_enum_OpClass.MemRead_swigconstant(_enum_OpClass)
MemRead = _enum_OpClass.MemRead

_enum_OpClass.MemWrite_swigconstant(_enum_OpClass)
MemWrite = _enum_OpClass.MemWrite

_enum_OpClass.IprAccess_swigconstant(_enum_OpClass)
IprAccess = _enum_OpClass.IprAccess

_enum_OpClass.InstPrefetch_swigconstant(_enum_OpClass)
InstPrefetch = _enum_OpClass.InstPrefetch

_enum_OpClass.Num_OpClass_swigconstant(_enum_OpClass)
Num_OpClass = _enum_OpClass.Num_OpClass

cvar = _enum_OpClass.cvar

