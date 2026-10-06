// ==============================================================================
// 🥋 Drill 32.1: AVX2 Integer SIMD Dot Product & Memory Width Casting
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -std=c++20 -Wall -Wextra day032_drill_01_sq8_avx2_dot.cpp -o drill32 && ./drill32
//
// CONTEXT:
// 8-bit integer SIMD processes 32 bytes per cycle (4x throughput over FP32 SIMD).
// In this drill, you will write the scalar loop and AVX2 16-lane integer dot product kernel.
//
// C++ CONCEPTS TO PRACTICE:
// 1. Pointer arithmetic: `const uint8_t* a` and `const int8_t* b`.
// 2. SIMD loads: `_mm_loadu_si128(reinterpret_cast<const __m128i*>(a + i))`.
// 3. Widening: `_mm256_cvtepu8_epi16` (uint8 -> int16) and `_mm256_cvtepi8_epi16` (int8 -> int16).
// 4. Multiply-Add: `_mm256_madd_epi16` multiplying 16-bit pairs and adding to 32-bit sums.
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cstdint>
#include <cassert>
#include <chrono>
#include <random>

// TODO 1: Implement scalar integer dot product
// Return sum of (a[i] * b[i]) as an int32_t for all i in [0, dim).
int32_t sq8_dot_scalar(const uint8_t* a, const int8_t* b, size_t dim) {
    // [YOUR CODE HERE]
    return 0;
}

#if defined(__AVX2__)
// TODO 2: Implement AVX2 16-lane integer dot product
// Steps:
// 1. Initialize accumulator: `__m256i acc = _mm256_setzero_si256();`
// 2. Loop in steps of 16 bytes: `i + 16 <= dim`:
//    a. Load 16 bytes: `_mm_loadu_si128(...)` for a and b.
//    b. Zero-extend uint8 -> int16: `_mm256_cvtepu8_epi16(raw_a)`.
//    c. Sign-extend int8  -> int16: `_mm256_cvtepi8_epi16(raw_b)`.
//    d. Multiply and add pairs: `_mm256_madd_epi16(va, vb)`.
//    e. Add to acc: `acc = _mm256_add_epi32(acc, prod32);`
// 3. Perform horizontal reduction of acc to a single int32_t.
// 4. Add remaining scalar elements in a tail loop.
int32_t sq8_dot_avx2(const uint8_t* a, const int8_t* b, size_t dim) {
    // [YOUR CODE HERE]
    return 0;
}
#endif

int main() {
    std::cout << "--- Drill 32.1: AVX2 SQ8 Integer SIMD Dot Product ---\n\n";

    constexpr size_t D = 128;
    std::vector<uint8_t> u(D);
    std::vector<int8_t> v(D);

    std::mt19937 rng(42);
    for (size_t i = 0; i < D; ++i) {
        u[i] = static_cast<uint8_t>(rng() % 256);
        v[i] = static_cast<int8_t>((rng() % 256) - 128);
    }

    int32_t expected = sq8_dot_scalar(u.data(), v.data(), D);

#if defined(__AVX2__)
    int32_t actual = sq8_dot_avx2(u.data(), v.data(), D);
    std::cout << "Scalar Dot Result: " << expected << "\n";
    std::cout << "AVX2 Dot Result:   " << actual << "\n";

    assert(expected == actual && "AVX2 result must match scalar ground truth!");
    std::cout << "\n✓ Drill Passed: AVX2 16-lane integer dot product verified!\n";
#endif
    return 0;
}
