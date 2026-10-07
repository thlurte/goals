// ==============================================================================
// 🥋 Drill 02 (Week 02 / Day 010): Agner Fog Ch 12 — AVX2 8-Lane L2 Squared Distance
//
// 📖 READING SOURCES:
// - Agner Fog: Optimizing Software in C++ (Ch 12: Vector Operations & YMM Registers)
//
// 🎯 CORE LESSON:
// 1. 256-bit YMM Registers hold 8 x 32-bit single-precision floats (`__m256`).
// 2. Unaligned load: `_mm256_loadu_ps`.
// 3. Fused Multiply-Add (FMA): `_mm256_fmadd_ps(diff, diff, acc)` computes `(diff * diff) + acc` in 1 cycle.
// 4. Horizontal reduction: Extract 128-bit halves, add, and reduce with `_mm_hadd_ps`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra drill_02_day010_avx2_l2_squared_baseline.cpp -o drill02 && ./drill02
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cassert>
#include <cmath>

#if defined(__AVX2__)
// TODO 1: Implement baseline AVX2 8-lane L2 squared distance
float l2_squared_avx2(const float* a, const float* b, size_t dim) {
    __m256 acc = _mm256_setzero_ps();
    size_t i{0};

    for (; i + 8 <= dim; i += 8) {
        __m256 va = _mm256_loadu_ps(a + i);
        __m256 vb = _mm256_loadu_ps(b + i);
        __m256 diff = _mm256_sub_ps(va, vb);
        acc = _mm256_fmadd_ps(diff, diff, acc);
    }

    // Horizontal reduction of acc (8 floats -> 1 float)
    alignas(32) float buf[8];
    _mm256_storeu_ps(buf, acc);
    float sum = buf[0] + buf[1] + buf[2] + buf[3] + buf[4] + buf[5] + buf[6] + buf[7];

    // Scalar cleanup tail loop
    for (; i < dim; ++i) {
        float d = a[i] - b[i];
        sum += d * d;
    }
    return sum;
}
#endif

int main() {
    std::cout << "--- Week 02 Drill 02: AVX2 8-Lane L2 Squared Distance ---\n\n";

    constexpr size_t D = 128;
    std::vector<float> a(D, 1.0f);
    std::vector<float> b(D, 3.0f);

    // Each dim diff = (1 - 3)^2 = 4. Total = 128 * 4 = 512.0
    float dist = l2_squared_avx2(a.data(), b.data(), D);
    std::cout << "AVX2 L2 Squared Distance: " << dist << " (Expected: 512.0)\n";

    assert(dist == 512.0f);
    std::cout << "\n✓ Week 02 Drill 02 Passed Successfully!\n";
    return 0;
}
