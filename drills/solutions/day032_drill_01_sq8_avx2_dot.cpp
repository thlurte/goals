/**
 * @file day032_drill_01_sq8_avx2_dot.cpp
 * @brief Drill 32.1: AVX2 Integer SIMD Dot Product & Pointer Arithmetic Mechanics
 *
 * 🎓 C++ CONCEPTS TAUGHT IN THIS DRILL:
 * 1. Pointers vs Array references (`const uint8_t*` vs `const uint8_t&`).
 * 2. `reinterpret_cast`: Converting byte pointers to 256-bit SIMD vector types (`const __m256i*`).
 * 3. 16-bit intermediate widening via `_mm256_cvtepu8_epi16` and `_mm256_cvtepi8_epi16`.
 * 4. SIMD horizontal reduction: Unpacking and adding vector lanes without slow scalar loops.
 *
 * Compile: g++ -O3 -march=native -mavx2 -std=c++20 -Wall -Wextra day032_drill_01_sq8_avx2_dot.cpp -o drill32 && ./drill32
 */

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cstdint>
#include <cassert>
#include <chrono>
#include <random>

int32_t sq8_dot_scalar(const uint8_t* a, const int8_t* b, size_t dim) {
    int32_t sum = 0;
    for (size_t i = 0; i < dim; ++i) {
        sum += static_cast<int32_t>(a[i]) * static_cast<int32_t>(b[i]);
    }
    return sum;
}

#if defined(__AVX2__)
int32_t sq8_dot_avx2(const uint8_t* a, const int8_t* b, size_t dim) {
    __m256i acc = _mm256_setzero_si256();

    size_t i = 0;
    // Process 16 bytes per iteration to avoid 16-bit intermediate overflow
    for (; i + 16 <= dim; i += 16) {
        __m128i raw_a = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + i));
        __m128i raw_b = _mm_loadu_si128(reinterpret_cast<const __m128i*>(b + i));

        __m256i va = _mm256_cvtepu8_epi16(raw_a); // Zero-extend uint8 -> int16
        __m256i vb = _mm256_cvtepi8_epi16(raw_b); // Sign-extend int8  -> int16

        // Multiply adjacent 16-bit pairs and add to 32-bit integers
        __m256i prod32 = _mm256_madd_epi16(va, vb);

        acc = _mm256_add_epi32(acc, prod32);
    }

    // Horizontal reduction of 8 x 32-bit integers in acc
    __m128i hi = _mm256_extracti128_si256(acc, 1);
    __m128i lo = _mm256_castsi256_si128(acc);
    __m128i sum128 = _mm_add_epi32(hi, lo);
    sum128 = _mm_hadd_epi32(sum128, sum128);
    sum128 = _mm_hadd_epi32(sum128, sum128);
    int32_t total = _mm_cvtsi128_si32(sum128);

    // Scalar cleanup for remainder
    for (; i < dim; ++i) {
        total += static_cast<int32_t>(a[i]) * static_cast<int32_t>(b[i]);
    }

    return total;
}
#endif

int main() {
    std::cout << "===================================================================\n";
    std::cout << "🥋 Drill 32.1: AVX2 32-Byte Integer SIMD & Memory Width Casting\n";
    std::cout << "===================================================================\n";

    constexpr size_t D = 128;
    constexpr size_t ITERS = 200000;

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
    std::cout << "[Verification] Scalar Dot: " << expected << " | AVX2 Dot: " << actual << "\n";
    assert(expected == actual && "AVX2 dot product does not match scalar ground truth!");

    auto t0 = std::chrono::high_resolution_clock::now();
    int32_t dummy = 0;
    for (size_t iter = 0; iter < ITERS; ++iter) {
        dummy += sq8_dot_avx2(u.data(), v.data(), D);
    }
    auto t1 = std::chrono::high_resolution_clock::now();

    double ms = std::chrono::duration<double, std::milli>(t1 - t0).count();
    double qps = (static_cast<double>(ITERS) / (ms / 1000.0));

    std::cout << "🚀 AVX2 SQ8 Throughput: " << (qps / 1e6) << " M dot products/sec (Dummy checksum: " << dummy << ")\n";
    std::cout << "\n✅ DRILL 32.1 PASSED: AVX2 integer dot product verified.\n";
#endif
    return 0;
}
