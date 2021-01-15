1. Generate llvm ir.
  <llvm_src_dir>/build/bin/clang -O0 -emit-llvm main.c -S -o main.ll

2. Run the llvm pass to generate dag
  <llvm_src_dir>/build/bin/opt -load <llvm_src_dir>/build/lib/LLVMIdentifyCriticalLoop.dylib -identifyCriticalLoop < main.ll
