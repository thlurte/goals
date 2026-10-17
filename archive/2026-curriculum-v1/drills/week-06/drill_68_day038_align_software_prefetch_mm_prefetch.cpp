// ==============================================================================
// 🥋 Drill: Software Prefetching via _mm_prefetch Intrinsics
//
// 📖 READING SOURCES:
// - Intel Intrinsics Guide: _mm_prefetch
// - CS:APP (Ch 6: Cache Memories)
//
// 🎯 CORE LESSON:
// 1. `_mm_prefetch((const char*)ptr, _MM_HINT_T0)` requests preloading a cache line into L1 cache.
// 2. `_MM_HINT_NTA` prefetches into a non-temporal structure, minimizing cache pollution.
// 3. Allows vector search engines to overlap CPU compute on vector $i$ with DRAM prefetching for vector $i + 4$.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_68_day038_align_software_prefetch_mm_prefetch.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <xmmintrin.h>
#include <vector>
#include <cassert>

int main() {
    std::cout << "--- Drill 68: Software Prefetching with _mm_prefetch ---\n\n";

    constexpr size_t N = 1024;
    std::vector<float> data(N, 2.5f);

    float sum = 0.0f;
    for (size_t i = 0; i < N; ++i) {
        // Prefetch 8 iterations ahead (64 bytes ahead)
        if (i + 16 < N) {
            _mm_prefetch(reinterpret_cast<const char*>(&data[i + 16]), _MM_HINT_T0);
        }
        sum += data[i];
    }

    assert(sum == N * 2.5f);
    std::cout << "Sum computed with interleaved software prefetching: " << sum << "\n";
    std::cout << "\n✓ Drill 68 Passed: _mm_prefetch intrinsic executed successfully!\n";
    return 0;
}
