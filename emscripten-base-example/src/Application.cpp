#include <emscripten/bind.h>
#include "calculation.h"
#include "libsweepcalculator.h"

using namespace emscripten;

float cppFunction(float a, float b, float t) {
    return substraction(a, b);
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("cppFunction", &cppFunction);
}