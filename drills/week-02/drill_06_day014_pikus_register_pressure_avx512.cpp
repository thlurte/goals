// ==============================================================================
// 🥋 Drill 06 (Week 02 / Day 014): Fedor Pikus Ch 3 — Register Pressure & AVX-512 Fallback
//
// 📖 READING SOURCES:
// - Fedor Pikus: The Art of Writing Efficient Programs (Ch 3: Register Pressure & ILP)
//
// 🎯 CORE LESSON:
// 1. Register Pressure:
//    AVX2 has 16 YMM registers. AVX-512 doubles this to 32 ZMM registers (`zmm0`..`zmm31`),
//    eliminating stack spilling under heavy loop unrolling.
// 2. Portable Fallback:
//    Guarding 512-bit code with `#if defined(__AVX512F__)` ensures clean compilation on AVX2 hardware.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -std=c++20 -Wall -Wextra drill_06_day014_pikus_register_pressure_avx512.cpp -o drill06 && ./drill06
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cassert>

float l2_distance_generic(const float* a, const float* b, size_t dim) {
#if defined(__AVX512F__)
    __m512 acc = _mm512_setzero_ps();
    size_t i{0};
    for (; i + 16 <= dim; i += 16) {
        __m512 va = _mm512_loadu_ps(a + i);
        __m512 vb = _mm512_loadu_ps(b + i);
        __m512 diff = _mm512_sub_ps(va, vb);
        acc = _mm512_fmadd_ps(diff, diff, acc);
    }
    float sum = _mm512_reduce_add_ps(acc);
    for (; i < dim; ++i) {
        float d = a[i] - b[i];
        sum += d * d;
    }
    return sum;
#elif defined(__AVX2__)
    __m256 acc = _mm256_setzero_ps();
    size_t i{0};
    for (; i + 8 <= dim; i += 8) {
        __m256 va = _mm256_loadu_ps(a + i);
        __m256 vb = _mm256_loadu_ps(b + i);
        __m256 diff = _mm256_sub_ps(va, vb);
        acc = _mm256_fmadd_ps(diff, diff, acc);
    }
    alignas(32) float buf[8];
    _mm256_storeu_ps(buf, acc);
    float sum = buf[0] + buf[1] + buf[2] + buf[3] + buf[4] + buf[5] + buf[6] + buf[7];
    for (; i < dim; ++i) {
        float d = a[i] - b[i];
        sum += d * d;
    }
    return sum;
#else
    float sum{0.0f};
    for (size_t i = 0; i < dim; ++i) {
        float d = a[i] - b[i];
        sum += d * d;
    }
    return sum;
#endif
}

int main() {
    std::cout << "--- Week 02 Drill 06: AVX-512 / AVX2 Portable Distance ---\n\n";

    constexpr size_t D = 128;
    std::vector<float> a(D, 1.0f);
    std::vector<float> b(D, 2.0f);

    float dist = l2_distance_generic(a.data(), b.data(), D);
    std::cout << "L2 Distance: " << dist << " (Expected: 128.0)\n";

    assert(dist == 128.0f);
    std::cout << "\n✓ Week 02 Drill 06 Passed Successfully!\n";
    return 0;
}
