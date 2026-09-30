// ==============================================================================
// 🥋 Drill 27.1: Software Prefetching (_mm_prefetch) & Cache Locality
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -std=c++20 -mavx2 -mfma day027_drill_01_cache_stride_prefetch.cpp -o drill27_1 && ./drill27_1
//
// CONTEXT:
// When streaming large arrays of high-dimensional vectors, L1/L2 cache misses
// stall the CPU. Software prefetching (_mm_prefetch) loads upcoming vectors
// into L1 cache before the CPU needs them, hiding DRAM latency (~50-70ns).
//
// C++ SYSTEMS LESSON:
// - Each CPU cache line is 64 bytes (16 floats).
// - `_mm_prefetch((const char*)ptr, _MM_HINT_T0)` requests cache line into L1 cache.
// - AVX2 vector dot product processes 8 floats per cycle using FMA (_mm256_fmadd_ps).
// ==============================================================================

#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <immintrin.h>
#include <cassert>

// TODO 1: Implement SIMD dot product with software prefetching
// Function: compute_dot_simd_prefetch(a, b, dim, next_b)
inline float compute_dot_simd_prefetch(const float* a, const float* b, size_t dim, const float* next_b) {
    // 1. If next_b != nullptr, prefetch its cache lines into L1 cache:
    //    Iterate through `offset` from 0 to `dim * sizeof(float)` with step 64:
    //    _mm_prefetch(reinterpret_cast<const char*>(next_b) + offset, _MM_HINT_T0);
    //
    // 2. Perform AVX2 FMA dot product of `a` and `b` (dim is multiple of 8):
    //    __m256 sum = _mm256_setzero_ps();
    //    for (size_t i = 0; i < dim; i += 8) {
    //        __m256 va = _mm256_loadu_ps(a + i);
    //        __m256 vb = _mm256_loadu_ps(b + i);
    //        sum = _mm256_fmadd_ps(va, vb, sum);
    //    }
    //
    // 3. Horizontally reduce `sum` and return float result.
    // [YOUR CODE HERE]
    return 0.0f;
}

int main() {
    std::cout << "--- Drill 27.1: Software Prefetching (_mm_prefetch) & Cache Locality ---\n\n";

    const size_t N = 10000;
    const size_t dim = 128; // 512 bytes per vector = 8 cache lines
    std::vector<float> dataset(N * dim, 1.0f);
    std::vector<float> query(dim, 2.0f);

    float total = 0.0f;
    const size_t lookahead = 8; // Prefetch 8 vectors ahead

    // Stream through dataset and compute dot product
    for (size_t i = 0; i < N; ++i) {
        const float* cur_vec = dataset.data() + i * dim;
        const float* next_vec = (i + lookahead < N) ? (dataset.data() + (i + lookahead) * dim) : nullptr;
        total += compute_dot_simd_prefetch(query.data(), cur_vec, dim, next_vec);
    }

    std::cout << "Computed total dot product across " << N << " vectors = " << total << "\n";
    assert(total == static_cast<float>(N * dim * 2.0f));
    std::cout << "✓ Drill Passed: Cache prefetching loop verified.\n";
    return 0;
}
