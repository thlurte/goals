// ==============================================================================
// 🥋 Drill 04 (Day 32.1): Intel Opt. Manual §5.3/14.4 — AVX2 Integer SIMD Dot Product
//
// 📖 READING SOURCES:
// - Intel 64 and IA-32 Architectures Optimization Reference Manual (§5.3 & §14.4)
//
// 🎯 CORE LESSON:
// 1. Vector integer multiply `_mm256_madd_epi16` executes on Port 0.
// 2. Pairwise Multiply-Add: `_mm256_madd_epi16` multiplies adjacent 16-bit pairs and
//    adds them horizontally into 32-bit sums in 1 cycle without overflow.
// 3. Widening: Unsigned bytes (uint8) zero-extend via `_mm256_cvtepu8_epi16`.
//              Signed bytes (int8) sign-extend via `_mm256_cvtepi8_epi16`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -std=c++20 -Wall -Wextra drill_04_day032_avx2_integer_dot.cpp -o drill04 && ./drill04
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cstdint>
#include <cassert>

// TODO 1: Implement scalar reference dot product
int32_t sq8_dot_scalar(const uint8_t* a, const int8_t* b, size_t dim) {
    int32_t sum{0};
    for (size_t i = 0; i < dim; ++i) {
        sum += static_cast<int32_t>(a[i]) * static_cast<int32_t>(b[i]);
    }
    return sum;
}

#if defined(__AVX2__)
// TODO 2: Implement AVX2 16-lane integer dot product
// 1. Loop i + 16 <= dim
// 2. Load 16 bytes for a and b using `_mm_loadu_si128`
// 3. Zero-extend a: `_mm256_cvtepu8_epi16`
// 4. Sign-extend b: `_mm256_cvtepi8_epi16`
// 5. Multiply-Add: `_mm256_madd_epi16`
// 6. Accumulate into __m256i acc with `_mm256_add_epi32`
// 7. Horizontal reduction + scalar tail loop
int32_t sq8_dot_avx2(const uint8_t* a, const int8_t* b, size_t dim) {
    // [YOUR CODE HERE]
    return 0;
}
#endif

int main() {
    std::cout << "--- Drill 04: Intel Opt. Manual AVX2 Integer Dot Product ---\n\n";

    constexpr size_t D = 128;
    std::vector<uint8_t> u(D);
    std::vector<int8_t> v(D);

    for (size_t i = 0; i < D; ++i) {
        u[i] = static_cast<uint8_t>(i % 256);
        v[i] = static_cast<int8_t>((i % 100) - 50);
    }

    int32_t expected = sq8_dot_scalar(u.data(), v.data(), D);
    int32_t actual = sq8_dot_avx2(u.data(), v.data(), D);

    std::cout << "Scalar Dot: " << expected << "\n";
    std::cout << "AVX2   Dot: " << actual << "\n";

    assert(expected == actual && "AVX2 result must match scalar result!");
    std::cout << "✓ Drill 04 Passed: AVX2 16-lane integer dot product verified!\n";
    return 0;
}
