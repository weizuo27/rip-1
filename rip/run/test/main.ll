; ModuleID = 'main.c'
source_filename = "main.c"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.13.0"

@.str = private unnamed_addr constant [7 x i8] c"matmul\00", align 1
@.str.1 = private unnamed_addr constant [17 x i8] c"A[N][N], B[N][N]\00", align 1
@.str.2 = private unnamed_addr constant [8 x i8] c"C[N][N]\00", align 1
@A = common global [1024 x [1024 x i32]] zeroinitializer, align 16
@B = common global [1024 x [1024 x i32]] zeroinitializer, align 16
@C = common global [1024 x [1024 x i32]] zeroinitializer, align 16
@.str.3 = private unnamed_addr constant [17 x i8] c"E[N][N], F[N][N]\00", align 1
@.str.4 = private unnamed_addr constant [8 x i8] c"D[N][N]\00", align 1
@E = common global [1024 x [1024 x i32]] zeroinitializer, align 16
@F = common global [1024 x [1024 x i32]] zeroinitializer, align 16
@D = common global [1024 x [1024 x i32]] zeroinitializer, align 16
@.str.5 = private unnamed_addr constant [17 x i8] c"C[N][N], D[N][N]\00", align 1
@.str.6 = private unnamed_addr constant [8 x i8] c"G[N][N]\00", align 1
@G = common global [1024 x [1024 x i32]] zeroinitializer, align 16

; Function Attrs: nounwind ssp uwtable
define i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %i1 = alloca i32, align 4
  %j1 = alloca i32, align 4
  %k1 = alloca i32, align 4
  %i2 = alloca i32, align 4
  %j2 = alloca i32, align 4
  %k2 = alloca i32, align 4
  %i3 = alloca i32, align 4
  %j3 = alloca i32, align 4
  %k3 = alloca i32, align 4
  %InLine = alloca i32, align 4
  %lat_hw = alloca double, align 8
  %lat_sw = alloca double, align 8
  %power_hw = alloca double, align 8
  %power_sw = alloca double, align 8
  %BRAM = alloca i32, align 4
  %DSP = alloca i32, align 4
  %LUT = alloca i32, align 4
  %FF = alloca i32, align 4
  %FuncName = alloca i8*, align 8
  %Inputs = alloca i8*, align 8
  %Outputs = alloca i8*, align 8
  %InLine26 = alloca i32, align 4
  %lat_hw27 = alloca double, align 8
  %lat_sw28 = alloca double, align 8
  %power_hw29 = alloca double, align 8
  %power_sw30 = alloca double, align 8
  %BRAM31 = alloca i32, align 4
  %DSP32 = alloca i32, align 4
  %LUT33 = alloca i32, align 4
  %FF34 = alloca i32, align 4
  %FuncName35 = alloca i8*, align 8
  %Inputs36 = alloca i8*, align 8
  %Outputs37 = alloca i8*, align 8
  %InLine70 = alloca i32, align 4
  %lat_hw71 = alloca double, align 8
  %lat_sw72 = alloca double, align 8
  %power_hw73 = alloca double, align 8
  %power_sw74 = alloca double, align 8
  %BRAM75 = alloca i32, align 4
  %DSP76 = alloca i32, align 4
  %LUT77 = alloca i32, align 4
  %FF78 = alloca i32, align 4
  %FuncName79 = alloca i8*, align 8
  %Inputs80 = alloca i8*, align 8
  %Outputs81 = alloca i8*, align 8
  store i32 0, i32* %retval, align 4
  store i32 0, i32* %i1, align 4
  store i32 0, i32* %i2, align 4
  store i32 0, i32* %i3, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc20, %entry
  %0 = load i32, i32* %i1, align 4
  %cmp = icmp slt i32 %0, 1024
  br i1 %cmp, label %for.body, label %for.end22

for.body:                                         ; preds = %for.cond
  store i32 1, i32* %InLine, align 4
  store double 1.000000e+01, double* %lat_hw, align 8
  store double 0x421795F5B6600000, double* %lat_sw, align 8
  store double 1.000000e+01, double* %power_hw, align 8
  store double 1.770000e+00, double* %power_sw, align 8
  store i32 10, i32* %BRAM, align 4
  store i32 10, i32* %DSP, align 4
  store i32 10, i32* %LUT, align 4
  store i32 10, i32* %FF, align 4
  store i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str, i32 0, i32 0), i8** %FuncName, align 8
  store i8* getelementptr inbounds ([17 x i8], [17 x i8]* @.str.1, i32 0, i32 0), i8** %Inputs, align 8
  store i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.2, i32 0, i32 0), i8** %Outputs, align 8
  store i32 0, i32* %j1, align 4
  br label %for.cond1

for.cond1:                                        ; preds = %for.inc17, %for.body
  %1 = load i32, i32* %j1, align 4
  %cmp2 = icmp slt i32 %1, 1024
  br i1 %cmp2, label %for.body3, label %for.end19

for.body3:                                        ; preds = %for.cond1
  store i32 0, i32* %k1, align 4
  br label %for.cond4

for.cond4:                                        ; preds = %for.inc, %for.body3
  %2 = load i32, i32* %k1, align 4
  %cmp5 = icmp slt i32 %2, 1024
  br i1 %cmp5, label %for.body6, label %for.end

for.body6:                                        ; preds = %for.cond4
  %3 = load i32, i32* %k1, align 4
  %idxprom = sext i32 %3 to i64
  %4 = load i32, i32* %i1, align 4
  %idxprom7 = sext i32 %4 to i64
  %arrayidx = getelementptr inbounds [1024 x [1024 x i32]], [1024 x [1024 x i32]]* @A, i64 0, i64 %idxprom7
  %arrayidx8 = getelementptr inbounds [1024 x i32], [1024 x i32]* %arrayidx, i64 0, i64 %idxprom
  %5 = load i32, i32* %arrayidx8, align 4
  %6 = load i32, i32* %j1, align 4
  %idxprom9 = sext i32 %6 to i64
  %7 = load i32, i32* %k1, align 4
  %idxprom10 = sext i32 %7 to i64
  %arrayidx11 = getelementptr inbounds [1024 x [1024 x i32]], [1024 x [1024 x i32]]* @B, i64 0, i64 %idxprom10
  %arrayidx12 = getelementptr inbounds [1024 x i32], [1024 x i32]* %arrayidx11, i64 0, i64 %idxprom9
  %8 = load i32, i32* %arrayidx12, align 4
  %mul = mul nsw i32 %5, %8
  %9 = load i32, i32* %j1, align 4
  %idxprom13 = sext i32 %9 to i64
  %10 = load i32, i32* %i1, align 4
  %idxprom14 = sext i32 %10 to i64
  %arrayidx15 = getelementptr inbounds [1024 x [1024 x i32]], [1024 x [1024 x i32]]* @C, i64 0, i64 %idxprom14
  %arrayidx16 = getelementptr inbounds [1024 x i32], [1024 x i32]* %arrayidx15, i64 0, i64 %idxprom13
  %11 = load i32, i32* %arrayidx16, align 4
  %add = add nsw i32 %11, %mul
  store i32 %add, i32* %arrayidx16, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body6
  %12 = load i32, i32* %k1, align 4
  %inc = add nsw i32 %12, 1
  store i32 %inc, i32* %k1, align 4
  br label %for.cond4

for.end:                                          ; preds = %for.cond4
  br label %for.inc17

for.inc17:                                        ; preds = %for.end
  %13 = load i32, i32* %j1, align 4
  %inc18 = add nsw i32 %13, 1
  store i32 %inc18, i32* %j1, align 4
  br label %for.cond1

for.end19:                                        ; preds = %for.cond1
  br label %for.inc20

for.inc20:                                        ; preds = %for.end19
  %14 = load i32, i32* %i1, align 4
  %inc21 = add nsw i32 %14, 1
  store i32 %inc21, i32* %i1, align 4
  br label %for.cond, !llvm.loop !2

for.end22:                                        ; preds = %for.cond
  br label %for.cond23

for.cond23:                                       ; preds = %for.inc64, %for.end22
  %15 = load i32, i32* %i2, align 4
  %cmp24 = icmp slt i32 %15, 1024
  br i1 %cmp24, label %for.body25, label %for.end66

for.body25:                                       ; preds = %for.cond23
  store i32 1, i32* %InLine26, align 4
  store double 1.000000e+01, double* %lat_hw27, align 8
  store double 0x421796E342E00000, double* %lat_sw28, align 8
  store double 1.000000e+01, double* %power_hw29, align 8
  store double 1.720000e+00, double* %power_sw30, align 8
  store i32 10, i32* %BRAM31, align 4
  store i32 10, i32* %DSP32, align 4
  store i32 10, i32* %LUT33, align 4
  store i32 10, i32* %FF34, align 4
  store i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str, i32 0, i32 0), i8** %FuncName35, align 8
  store i8* getelementptr inbounds ([17 x i8], [17 x i8]* @.str.3, i32 0, i32 0), i8** %Inputs36, align 8
  store i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.4, i32 0, i32 0), i8** %Outputs37, align 8
  store i32 0, i32* %j2, align 4
  br label %for.cond38

for.cond38:                                       ; preds = %for.inc61, %for.body25
  %16 = load i32, i32* %j2, align 4
  %cmp39 = icmp slt i32 %16, 1024
  br i1 %cmp39, label %for.body40, label %for.end63

for.body40:                                       ; preds = %for.cond38
  store i32 0, i32* %k2, align 4
  br label %for.cond41

for.cond41:                                       ; preds = %for.inc58, %for.body40
  %17 = load i32, i32* %k2, align 4
  %cmp42 = icmp slt i32 %17, 1024
  br i1 %cmp42, label %for.body43, label %for.end60

for.body43:                                       ; preds = %for.cond41
  %18 = load i32, i32* %k2, align 4
  %idxprom44 = sext i32 %18 to i64
  %19 = load i32, i32* %i2, align 4
  %idxprom45 = sext i32 %19 to i64
  %arrayidx46 = getelementptr inbounds [1024 x [1024 x i32]], [1024 x [1024 x i32]]* @E, i64 0, i64 %idxprom45
  %arrayidx47 = getelementptr inbounds [1024 x i32], [1024 x i32]* %arrayidx46, i64 0, i64 %idxprom44
  %20 = load i32, i32* %arrayidx47, align 4
  %21 = load i32, i32* %j2, align 4
  %idxprom48 = sext i32 %21 to i64
  %22 = load i32, i32* %k2, align 4
  %idxprom49 = sext i32 %22 to i64
  %arrayidx50 = getelementptr inbounds [1024 x [1024 x i32]], [1024 x [1024 x i32]]* @F, i64 0, i64 %idxprom49
  %arrayidx51 = getelementptr inbounds [1024 x i32], [1024 x i32]* %arrayidx50, i64 0, i64 %idxprom48
  %23 = load i32, i32* %arrayidx51, align 4
  %mul52 = mul nsw i32 %20, %23
  %24 = load i32, i32* %j2, align 4
  %idxprom53 = sext i32 %24 to i64
  %25 = load i32, i32* %i2, align 4
  %idxprom54 = sext i32 %25 to i64
  %arrayidx55 = getelementptr inbounds [1024 x [1024 x i32]], [1024 x [1024 x i32]]* @D, i64 0, i64 %idxprom54
  %arrayidx56 = getelementptr inbounds [1024 x i32], [1024 x i32]* %arrayidx55, i64 0, i64 %idxprom53
  %26 = load i32, i32* %arrayidx56, align 4
  %add57 = add nsw i32 %26, %mul52
  store i32 %add57, i32* %arrayidx56, align 4
  br label %for.inc58

for.inc58:                                        ; preds = %for.body43
  %27 = load i32, i32* %k2, align 4
  %inc59 = add nsw i32 %27, 1
  store i32 %inc59, i32* %k2, align 4
  br label %for.cond41

for.end60:                                        ; preds = %for.cond41
  br label %for.inc61

for.inc61:                                        ; preds = %for.end60
  %28 = load i32, i32* %j2, align 4
  %inc62 = add nsw i32 %28, 1
  store i32 %inc62, i32* %j2, align 4
  br label %for.cond38

for.end63:                                        ; preds = %for.cond38
  br label %for.inc64

for.inc64:                                        ; preds = %for.end63
  %29 = load i32, i32* %i2, align 4
  %inc65 = add nsw i32 %29, 1
  store i32 %inc65, i32* %i2, align 4
  br label %for.cond23, !llvm.loop !4

for.end66:                                        ; preds = %for.cond23
  br label %for.cond67

for.cond67:                                       ; preds = %for.inc108, %for.end66
  %30 = load i32, i32* %i3, align 4
  %cmp68 = icmp slt i32 %30, 1024
  br i1 %cmp68, label %for.body69, label %for.end110

for.body69:                                       ; preds = %for.cond67
  store i32 1, i32* %InLine70, align 4
  store double 1.000000e+01, double* %lat_hw71, align 8
  store double 0x4242E2B3866C0000, double* %lat_sw72, align 8
  store double 1.000000e+01, double* %power_hw73, align 8
  store double 1.720000e+00, double* %power_sw74, align 8
  store i32 10, i32* %BRAM75, align 4
  store i32 10, i32* %DSP76, align 4
  store i32 10, i32* %LUT77, align 4
  store i32 10, i32* %FF78, align 4
  store i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str, i32 0, i32 0), i8** %FuncName79, align 8
  store i8* getelementptr inbounds ([17 x i8], [17 x i8]* @.str.5, i32 0, i32 0), i8** %Inputs80, align 8
  store i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.6, i32 0, i32 0), i8** %Outputs81, align 8
  store i32 0, i32* %j3, align 4
  br label %for.cond82

for.cond82:                                       ; preds = %for.inc105, %for.body69
  %31 = load i32, i32* %j3, align 4
  %cmp83 = icmp slt i32 %31, 1024
  br i1 %cmp83, label %for.body84, label %for.end107

for.body84:                                       ; preds = %for.cond82
  store i32 0, i32* %k3, align 4
  br label %for.cond85

for.cond85:                                       ; preds = %for.inc102, %for.body84
  %32 = load i32, i32* %k3, align 4
  %cmp86 = icmp slt i32 %32, 1024
  br i1 %cmp86, label %for.body87, label %for.end104

for.body87:                                       ; preds = %for.cond85
  %33 = load i32, i32* %k3, align 4
  %idxprom88 = sext i32 %33 to i64
  %34 = load i32, i32* %i3, align 4
  %idxprom89 = sext i32 %34 to i64
  %arrayidx90 = getelementptr inbounds [1024 x [1024 x i32]], [1024 x [1024 x i32]]* @C, i64 0, i64 %idxprom89
  %arrayidx91 = getelementptr inbounds [1024 x i32], [1024 x i32]* %arrayidx90, i64 0, i64 %idxprom88
  %35 = load i32, i32* %arrayidx91, align 4
  %36 = load i32, i32* %j3, align 4
  %idxprom92 = sext i32 %36 to i64
  %37 = load i32, i32* %k3, align 4
  %idxprom93 = sext i32 %37 to i64
  %arrayidx94 = getelementptr inbounds [1024 x [1024 x i32]], [1024 x [1024 x i32]]* @D, i64 0, i64 %idxprom93
  %arrayidx95 = getelementptr inbounds [1024 x i32], [1024 x i32]* %arrayidx94, i64 0, i64 %idxprom92
  %38 = load i32, i32* %arrayidx95, align 4
  %mul96 = mul nsw i32 %35, %38
  %39 = load i32, i32* %j3, align 4
  %idxprom97 = sext i32 %39 to i64
  %40 = load i32, i32* %i3, align 4
  %idxprom98 = sext i32 %40 to i64
  %arrayidx99 = getelementptr inbounds [1024 x [1024 x i32]], [1024 x [1024 x i32]]* @G, i64 0, i64 %idxprom98
  %arrayidx100 = getelementptr inbounds [1024 x i32], [1024 x i32]* %arrayidx99, i64 0, i64 %idxprom97
  %41 = load i32, i32* %arrayidx100, align 4
  %add101 = add nsw i32 %41, %mul96
  store i32 %add101, i32* %arrayidx100, align 4
  br label %for.inc102

for.inc102:                                       ; preds = %for.body87
  %42 = load i32, i32* %k3, align 4
  %inc103 = add nsw i32 %42, 1
  store i32 %inc103, i32* %k3, align 4
  br label %for.cond85

for.end104:                                       ; preds = %for.cond85
  br label %for.inc105

for.inc105:                                       ; preds = %for.end104
  %43 = load i32, i32* %j3, align 4
  %inc106 = add nsw i32 %43, 1
  store i32 %inc106, i32* %j3, align 4
  br label %for.cond82

for.end107:                                       ; preds = %for.cond82
  br label %for.inc108

for.inc108:                                       ; preds = %for.end107
  %44 = load i32, i32* %i3, align 4
  %inc109 = add nsw i32 %44, 1
  store i32 %inc109, i32* %i3, align 4
  br label %for.cond67, !llvm.loop !5

for.end110:                                       ; preds = %for.cond67
  ret i32 0
}

attributes #0 = { nounwind ssp uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"clang version 3.9.0 (tags/RELEASE_390/final)"}
!2 = distinct !{!2, !3}
!3 = !{!"llvm.loop.critical", i1 true}
!4 = distinct !{!4, !3}
!5 = distinct !{!5, !3}
