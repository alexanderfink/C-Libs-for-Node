#include "calculation.h"

int substraction(int a, int b) {
  return a - b;
}

// clang -c -o lib-calc-clang.o calculation.cpp
// ar r lib-calc-clang.a lib-calc-clang.o

// emcc -c -o lib-calc-emcc.o calculation.cpp
// emar rcs lib-calc-emcc.a lib-calc-emcc.o