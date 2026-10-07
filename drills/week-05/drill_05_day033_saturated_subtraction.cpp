// ==============================================================================
// 🥋 Drill 05 (Day 33.2): Agner Fog Ch 12 — Saturated Arithmetic & L1 Distance SAD
//
// 📖 READING SOURCES:
// - Agner Fog: Optimizing Software in C++ (Ch 12: Vector Operations & Integer SIMD)
//
// 🎯 CORE LESSON:
// 1. Standard unsigned subtraction wraps around 256: (0 - 5 = 251).
// 2. Saturated unsigned subtraction (_mm256_subs_epu8) clamps underflow to 0.
// 3. Absolute byte difference without branches: |a - b| = (a -_sat b) | (b -_sat a).
// 4. Sum of Absolute Differences: `_mm256_sad_epu8` horizontally sums 8 byte diffs in 1 cycle.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -std=c++20 -Wall -Wextra drill_05_day033_saturated_subtraction.cpp -o drill05 && ./drill05
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cstdint>
#include <cassert>
#include <cmath>

// TODO 1: Implement scalar L1 distance
uint32_t l1_distance_scalar(const uint8_t* a, const uint8_t* b, size_t dim) {
    uint32_t total{0};
    for (size_t i = 0; i < dim; ++i) {
        total += static_cast<uint32_t>(std::abs(static_cast<int>(a[i]) - static_cast<int>(b[i])));
    }
    return total;
}

#if defined(__AVX2__)
// TODO 2: Implement AVX2 L1 distance using saturated subtraction (_mm256_subs_epu8)
// Processes 32 dimensions in parallel per iteration!
uint32_t l1_distance_avx2(const uint8_t* a, const uint8_t* b, size_t dim) {
    // [YOUR CODE HERE]
    return 0;
}
#endif

int main() {
    std::cout << "--- Drill 05: Agner Fog Ch 12 Saturated Subtraction & SAD ---\n\n";

    constexpr size_t D = 128;
    std::vector<uint8_t> x(D), y(D);
    for (size_t i = 0; i < D; ++i) {
        x[i] = static_cast<uint8_t>(i * 3 % 256);
        y[i] = static_cast<uint8_t>((i * 7 + 13) % 256);
    }

    uint32_t ground_truth = l1_distance_scalar(x.data(), y.data(), D);
    uint32_t avx2_result = l1_distance_avx2(x.data(), y.data(), D);

    std::cout << "Scalar L1 Distance: " << ground_truth << "\n";
    std::cout << "AVX2   L1 Distance: " << avx2_result << "\n";

    assert(ground_truth == avx2_result && "AVX2 saturated subtraction result mismatch!");
    std::cout << "✓ Drill 05 Passed: Saturated subtraction and SAD verified!\n";
    return 0;
}
