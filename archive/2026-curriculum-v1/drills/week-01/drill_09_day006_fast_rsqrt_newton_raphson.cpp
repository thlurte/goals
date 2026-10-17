// ==============================================================================
// 🥋 Drill 09 (Week 01 / Day 006): Agner Fog Ch 7 — Fast Reciprocal Square Root & Denormals
//
// 📖 READING SOURCES:
// - Agner Fog: Optimizing Software in C++ (Ch 7: Floating-Point Operations & Denormals)
//
// 🎯 CORE LESSON:
// 1. Division & Square Root Latencies:
//    Floating point division (`/`) and `sqrt` take 12-14 clock cycles on modern CPUs.
// 2. Fast Reciprocal Square Root (rsqrt):
//    `1.0f / sqrt(x)` via 1-step Newton-Raphson refinement:
//    y_{n+1} = y_n * (1.5 - 0.5 * x * y_n^2)
// 3. Denormal Floats:
//    Numbers very close to 0 trigger microcode traps (slowing down execution by 100x)
//    unless Flush-To-Zero (FTZ) and Denormals-Are-Zero (DAZ) are active.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_09_day006_fast_rsqrt_newton_raphson.cpp -o drill09 && ./drill09
// ==============================================================================

#include <iostream>
#include <cmath>
#include <cstdint>
#include <bit>
#include <cassert>

// Fast reciprocal square root approximation with 1 Newton-Raphson step
float fast_rsqrt(float number) {
    uint32_t i = std::bit_cast<uint32_t>(number);
    i = 0x5f3759df - (i >> 1); // Quake III magic constant initial seed
    float y = std::bit_cast<float>(i);
    // 1-step Newton-Raphson refinement
    y = y * (1.5f - (0.5f * number * y * y));
    return y;
}

int main() {
    std::cout << "--- Week 01 Drill 09: Fast Reciprocal Square Root (rsqrt) ---\n\n";

    float x = 25.0f;
    float approx = fast_rsqrt(x);
    float exact = 1.0f / std::sqrt(x); // 1 / 5 = 0.20

    std::cout << "Exact 1/sqrt(25.0):  " << exact << "\n";
    std::cout << "Approx 1/sqrt(25.0): " << approx << "\n";

    assert(std::abs(approx - exact) < 1e-3f);
    std::cout << "\n✓ Week 01 Drill 09 Passed Successfully!\n";
    return 0;
}
