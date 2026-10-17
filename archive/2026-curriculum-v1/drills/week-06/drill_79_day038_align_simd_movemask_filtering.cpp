// ==============================================================================
// 🥋 Drill: SIMD Bitmask Extraction: _mm256_movemask_ps
//
// 📖 READING SOURCES:
// - Intel Intrinsics Guide: _mm256_movemask_ps
// - Fog: Optimizing Subroutines in Assembly Language
//
// 🎯 CORE LESSON:
// 1. `_mm256_cmp_ps` performs 8 parallel comparisons returning 32-bit float masks (`0xFFFFFFFF` or `0`).
// 2. `_mm256_movemask_ps` compresses the MSB of all 8 lanes into an 8-bit scalar integer.
// 3. Allows instant branchless evaluation of metadata filter predicates.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_79_day038_align_simd_movemask_filtering.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <immintrin.h>
#include <cassert>

int main() {
    std::cout << "--- Drill 79: _mm256_movemask_ps Filter Bitmask ---\n\n";

    alignas(32) float scores[8] = {0.1f, 0.9f, 0.3f, 0.85f, 0.2f, 0.95f, 0.4f, 0.88f};
    __m256 v_scores = _mm256_load_ps(scores);
    __m256 v_threshold = _mm256_set1_ps(0.8f);

    // Compare scores > threshold
    __m256 v_cmp = _mm256_cmp_ps(v_scores, v_threshold, _CMP_GT_OQ);

    // Extract bitmask (1 if > threshold, 0 otherwise)
    int mask = _mm256_movemask_ps(v_cmp);

    // Indices 1, 3, 5, 7 exceed 0.8: bits 1, 3, 5, 7 set = 0xAA (10101010 in binary)
    assert(mask == 0xAA);

    std::cout << "Extracted bitmask: 0x" << std::hex << mask << std::dec << "\n";
    std::cout << "\n✓ Drill 79 Passed: _mm256_movemask_ps predicate extraction verified!\n";
    return 0;
}
