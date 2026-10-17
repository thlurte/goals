// ==============================================================================
// 🥋 Drill 03 (Week 03 / Day 019): CS:APP §6.6 & Pikus Ch 4 — Software Prefetching
//
// 📖 READING SOURCES:
// - Fedor Pikus: The Art of Writing Efficient Programs (Ch 4: Software Prefetching)
//
// 🎯 CORE LESSON:
// 1. `_mm_prefetch(ptr, _MM_HINT_T0)`:
//    Asynchronously instructs hardware memory controllers to fetch cache lines into L1D cache
//    ahead of CPU execution, hiding DRAM latency.
// 2. Prefetch Distance K:
//    Too small: data arrives too late. Too large: prefetched data gets evicted before use.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -std=c++20 -Wall -Wextra drill_03_day019_software_prefetching_simd.cpp -o drill03 && ./drill03
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cassert>

float scan_with_prefetch(const float* data, size_t num_vectors, size_t dim, size_t prefetch_dist) {
    float total{0.0f};
    for (size_t i = 0; i < num_vectors; ++i) {
        // Prefetch upcoming vector
        if (i + prefetch_dist < num_vectors) {
            _mm_prefetch(
                reinterpret_cast<const char*>(data + (i + prefetch_dist) * dim),
                _MM_HINT_T0
            );
        }

        const float* vec = data + i * dim;
        for (size_t d = 0; d < dim; ++d) {
            total += vec[d];
        }
    }
    return total;
}

int main() {
    std::cout << "--- Week 03 Drill 03: Software Prefetching (_mm_prefetch) ---\n\n";

    constexpr size_t N = 1000, D = 128;
    std::vector<float> data(N * D, 1.0f);

    float sum = scan_with_prefetch(data.data(), N, D, 4);
    std::cout << "Scanned Sum with Prefetching: " << sum << " (Expected: " << (N * D) << ")\n";

    assert(sum == static_cast<float>(N * D));
    std::cout << "\n✓ Week 03 Drill 03 Passed Successfully!\n";
    return 0;
}
