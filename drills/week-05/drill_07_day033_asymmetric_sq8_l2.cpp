// ==============================================================================
// 🥋 Drill 07 (Day 33.4): Jégou PQ §3.1–3.3 — Asymmetric SQ8 Distance Kernel (ADC)
//
// 📖 READING SOURCES:
// - Jégou, Douze, Schmid: "Product Quantization for Nearest Neighbor Search" (IEEE TPAMI)
//
// 🎯 CORE LESSON:
// 1. Asymmetric Distance Computation (ADC):
//    Keep query unquantized in FP32; pre-scale query q'[i] = (q[i] - x_min) / step.
// 2. Direct distance computation:
//    ||q - x_hat||^2 = sum (q'[i] - code[i])^2 * step^2.
// 3. Widening unsigned uint8 codes to FP32 registers in AVX2:
//    `_mm256_cvtepu8_epi32` + `_mm256_cvtepi32_ps`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra drill_07_day033_asymmetric_sq8_l2.cpp -o drill07 && ./drill07
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cstdint>
#include <cassert>
#include <cmath>

// TODO 1: Implement AVX2 Asymmetric L2 SQ8 Distance Kernel
float asymmetric_l2_sq8_avx2(
    const float* query_scaled,
    const uint8_t* base_sq8,
    size_t dim,
    float step_sq
) {
    // [YOUR CODE HERE]
    return 0.0f;
}

int main() {
    std::cout << "--- Drill 07: Jégou PQ Asymmetric SQ8 Distance Kernel (ADC) ---\n\n";

    constexpr size_t D = 128;
    float step = 0.05f;
    std::vector<float> q_scaled(D, 10.0f);
    std::vector<uint8_t> base(D, 8);

    float dist = asymmetric_l2_sq8_avx2(q_scaled.data(), base.data(), D, step * step);
    std::cout << "Computed ADC Distance: " << dist << " (Expected: 1.28)\n";

    assert(std::abs(dist - 1.28f) < 1e-4f);
    std::cout << "✓ Drill 07 Passed: Asymmetric distance kernel verified!\n";
    return 0;
}
