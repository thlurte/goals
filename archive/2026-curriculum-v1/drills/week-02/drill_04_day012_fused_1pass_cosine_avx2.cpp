// ==============================================================================
// 🥋 Drill 04 (Week 02 / Day 012): Agner Fog Ch 11 — Fused 1-Pass Cosine Distance AVX2
//
// 📖 READING SOURCES:
// - Agner Fog: Optimizing Software in C++ (Ch 11: FMA Operations & Port Mapping)
//
// 🎯 CORE LESSON:
// 1. 2-Pass Cosine vs 1-Pass Fused Cosine:
//    - 2-Pass loads vectors twice from memory (computing dot product, then norms).
//    - 1-Pass fused computes dot product `a[i]*b[i]`, `norm_a += a[i]^2`, and `norm_b += b[i]^2`
//      concurrently in the same loop, cutting memory bus traffic by 50%!
// 2. Cosine Distance Formula:
//    CosineDistance(a, b) = 1.0f - (dot / (sqrt(norm_a) * sqrt(norm_b)))
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra drill_04_day012_fused_1pass_cosine_avx2.cpp -o drill04 && ./drill04
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cmath>
#include <cassert>

float cosine_distance_fused_avx2(const float* a, const float* b, size_t dim) {
    __m256 acc_dot = _mm256_setzero_ps();
    __m256 acc_na = _mm256_setzero_ps();
    __m256 acc_nb = _mm256_setzero_ps();

    size_t i{0};
    for (; i + 8 <= dim; i += 8) {
        __m256 va = _mm256_loadu_ps(a + i);
        __m256 vb = _mm256_loadu_ps(b + i);

        acc_dot = _mm256_fmadd_ps(va, vb, acc_dot);
        acc_na  = _mm256_fmadd_ps(va, va, acc_na);
        acc_nb  = _mm256_fmadd_ps(vb, vb, acc_nb);
    }

    alignas(32) float buf_dot[8], buf_na[8], buf_nb[8];
    _mm256_storeu_ps(buf_dot, acc_dot);
    _mm256_storeu_ps(buf_na, acc_na);
    _mm256_storeu_ps(buf_nb, acc_nb);

    float dot = buf_dot[0] + buf_dot[1] + buf_dot[2] + buf_dot[3] + buf_dot[4] + buf_dot[5] + buf_dot[6] + buf_dot[7];
    float na  = buf_na[0]  + buf_na[1]  + buf_na[2]  + buf_na[3]  + buf_na[4]  + buf_na[5]  + buf_na[6]  + buf_na[7];
    float nb  = buf_nb[0]  + buf_nb[1]  + buf_nb[2]  + buf_nb[3]  + buf_nb[4]  + buf_nb[5]  + buf_nb[6]  + buf_nb[7];

    for (; i < dim; ++i) {
        dot += a[i] * b[i];
        na  += a[i] * a[i];
        nb  += b[i] * b[i];
    }

    float denom = std::sqrt(na) * std::sqrt(nb);
    if (denom < 1e-12f) return 1.0f;
    return 1.0f - (dot / denom);
}

int main() {
    std::cout << "--- Week 02 Drill 04: Fused 1-Pass Cosine Distance AVX2 ---\n\n";

    constexpr size_t D = 128;
    std::vector<float> a(D, 1.0f);
    std::vector<float> b(D, 2.0f); // Parallel vectors -> cosine distance = 0.0

    float cos_dist = cosine_distance_fused_avx2(a.data(), b.data(), D);
    std::cout << "Computed Cosine Distance: " << cos_dist << " (Expected: 0.0)\n";

    assert(std::abs(cos_dist) < 1e-5f);
    std::cout << "\n✓ Week 02 Drill 04 Passed Successfully!\n";
    return 0;
}
