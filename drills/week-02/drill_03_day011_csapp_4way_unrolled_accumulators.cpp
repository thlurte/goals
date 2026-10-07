// ==============================================================================
// 🥋 Drill 03 (Week 02 / Day 011): CS:APP §5.8–5.9 — 4-Way Multi-Accumulator Unrolling
//
// 📖 READING SOURCES:
// - Bryant & O'Hallaron: Computer Systems (CS:APP 3rd Ed, §5.8–5.9: Multi-Accumulator Unrolling)
//
// 🎯 CORE LESSON:
// 1. 4-Way Parallel Accumulation:
//    Using 4 independent accumulator registers (`acc0`, `acc1`, `acc2`, `acc3`)
//    processes 32 floats per iteration and completely saturates FMA pipelines.
// 2. Register Allocation:
//    x86-64 AVX2 provides 16 YMM registers (`ymm0`..`ymm15`). 4 accumulators + 4 vector loads
//    occupy 8 registers, staying well under the 16-register spilling threshold.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra drill_03_day011_csapp_4way_unrolled_accumulators.cpp -o drill03 && ./drill03
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cassert>

float l2_squared_avx2_unroll4(const float* a, const float* b, size_t dim) {
    __m256 acc0 = _mm256_setzero_ps();
    __m256 acc1 = _mm256_setzero_ps();
    __m256 acc2 = _mm256_setzero_ps();
    __m256 acc3 = _mm256_setzero_ps();

    size_t i{0};
    for (; i + 32 <= dim; i += 32) {
        __m256 va0 = _mm256_loadu_ps(a + i);
        __m256 vb0 = _mm256_loadu_ps(b + i);
        __m256 diff0 = _mm256_sub_ps(va0, vb0);
        acc0 = _mm256_fmadd_ps(diff0, diff0, acc0);

        __m256 va1 = _mm256_loadu_ps(a + i + 8);
        __m256 vb1 = _mm256_loadu_ps(b + i + 8);
        __m256 diff1 = _mm256_sub_ps(va1, vb1);
        acc1 = _mm256_fmadd_ps(diff1, diff1, acc1);

        __m256 va2 = _mm256_loadu_ps(a + i + 16);
        __m256 vb2 = _mm256_loadu_ps(b + i + 16);
        __m256 diff2 = _mm256_sub_ps(va2, vb2);
        acc2 = _mm256_fmadd_ps(diff2, diff2, acc2);

        __m256 va3 = _mm256_loadu_ps(a + i + 24);
        __m256 vb3 = _mm256_loadu_ps(b + i + 24);
        __m256 diff3 = _mm256_sub_ps(va3, vb3);
        acc3 = _mm256_fmadd_ps(diff3, diff3, acc3);
    }

    __m256 sum01 = _mm256_add_ps(acc0, acc1);
    __m256 sum23 = _mm256_add_ps(acc2, acc3);
    __m256 total_vec = _mm256_add_ps(sum01, sum23);

    alignas(32) float buf[8];
    _mm256_storeu_ps(buf, total_vec);
    float sum = buf[0] + buf[1] + buf[2] + buf[3] + buf[4] + buf[5] + buf[6] + buf[7];

    for (; i < dim; ++i) {
        float d = a[i] - b[i];
        sum += d * d;
    }
    return sum;
}

int main() {
    std::cout << "--- Week 02 Drill 03: 4-Way Parallel Accumulators ---\n\n";

    constexpr size_t D = 128;
    std::vector<float> a(D, 2.0f);
    std::vector<float> b(D, 5.0f);

    // Each dim diff = (2 - 5)^2 = 9. Total = 128 * 9 = 1152.0
    float dist = l2_squared_avx2_unroll4(a.data(), b.data(), D);
    std::cout << "4-Way Unrolled L2 Distance: " << dist << " (Expected: 1152.0)\n";

    assert(dist == 1152.0f);
    std::cout << "\n✓ Week 02 Drill 03 Passed Successfully!\n";
    return 0;
}
