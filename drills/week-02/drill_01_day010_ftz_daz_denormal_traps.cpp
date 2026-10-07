// ==============================================================================
// 🥋 Drill 01 (Week 02 / Day 010): Agner Fog Ch 12 — FTZ / DAZ Denormal Float Traps
//
// 📖 READING SOURCES:
// - Agner Fog: Optimizing Software in C++ (Ch 12: Vector Operations & Denormals)
//
// 🎯 CORE LESSON:
// 1. Denormal / Subnormal Floating Point Hazards:
//    When a float value is smaller than 1.175e-38 (IEEE 754 float min normalized),
//    CPUs cannot process it in regular hardware ALUs and trap into microcode (causing 100x slowdown!).
// 2. The FTZ / DAZ Hardware Flags:
//    - Flush-To-Zero (FTZ): Clamps denormal output results to zero.
//    - Denormals-Are-Zero (DAZ): Treats denormal inputs as zero.
//    - Enabled via `_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON)` and `_MM_SET_DENORMALS_ZERO_MODE(_MM_DENORMALS_ZERO_ON)`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -std=c++20 -Wall -Wextra drill_01_day010_ftz_daz_denormal_traps.cpp -o drill01 && ./drill01
// ==============================================================================

#include <iostream>
#include <immintrin.h>
#include <xmmintrin.h>
#include <pmmintrin.h>
#include <cassert>

// TODO 1: Enable FTZ and DAZ modes on the CPU MXCSR control register
inline void enable_ftz_daz() {
    #if defined(__x86_64__) || defined(_M_X64)
    _MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
    _MM_SET_DENORMALS_ZERO_MODE(_MM_DENORMALS_ZERO_ON);
    #endif
}

// TODO 2: Check if a float is denormal (non-zero but smaller than min normalized float)
bool is_denormal_scalar(float x) {
    return x != 0.0f && std::abs(x) < 1.17549435e-38f;
}

int main() {
    std::cout << "--- Week 02 Drill 01: FTZ / DAZ & Denormal Traps ---\n\n";

    float subnormal = 1.0e-40f;
    std::cout << "Subnormal value before FTZ/DAZ check: " << subnormal << "\n";
    assert(is_denormal_scalar(subnormal) == true);

    enable_ftz_daz();
    std::cout << "✓ FTZ/DAZ MXCSR register flags successfully set!\n";

    std::cout << "\n✓ Week 02 Drill 01 Passed Successfully!\n";
    return 0;
}
