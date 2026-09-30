#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <immintrin.h>
#include <cassert>

// ==============================================================================
// 🥋 Drill 27.1: Cache-Line Stride & Software Prefetching (_mm_prefetch)
//
// CONTEXT:
// When streaming large arrays of high-dimensional vectors, L1/L2 cache misses
// stall the CPU. Hardware prefetchers handle simple sequential patterns, but
// multi-list or strided access benefits from explicit software prefetching.
//
// C++ SYSTEMS LESSON:
// - Each CPU cache line is 64 bytes (16 floats).
// - `_mm_prefetch((const char*)ptr, _MM_HINT_T0)` loads the cache line into L1 cache.
// - Lookahead distance must be tuned (typically 4 to 16 cache lines ahead) to hide
//   DRAM latency (~50-70ns) without evicting active data.
// ==============================================================================

inline float compute_dot_simd_prefetch(const float* a, const float* b, size_t dim, const float* next_b) {
    // Prefetch upcoming vector cache lines (each 64 bytes = 16 floats)
    if (next_b != nullptr) {
        const char* p = reinterpret_cast<const char*>(next_b);
        for (size_t offset = 0; offset < dim * sizeof(float); offset += 64) {
            _mm_prefetch(p + offset, _MM_HINT_T0);
        }
    }

    __m256 sum = _mm256_setzero_ps();
    for (size_t i = 0; i < dim; i += 8) {
        __m256 va = _mm256_loadu_ps(a + i);
        __m256 vb = _mm256_loadu_ps(b + i);
        sum = _mm256_fmadd_ps(va, vb, sum);
    }

    // Horizontal sum
    __m128 lo = _mm256_castps256_ps128(sum);
    __m128 hi = _mm256_extractf128_ps(sum, 1);
    __m128 s = _mm_add_ps(lo, hi);
    s = _mm_hadd_ps(s, s);
    s = _mm_hadd_ps(s, s);
    return _mm_cvtss_f32(s);
}

int main() {
    std::cout << "--- Drill 27.1: Software Prefetching (_mm_prefetch) & Cache Locality ---\n\n";

    const size_t N = 10000;
    const size_t dim = 128; // 512 bytes per vector = 8 cache lines
    std::vector<float> dataset(N * dim, 1.0f);
    std::vector<float> query(dim, 2.0f);

    float total = 0.0f;
    const size_t lookahead = 8;

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
