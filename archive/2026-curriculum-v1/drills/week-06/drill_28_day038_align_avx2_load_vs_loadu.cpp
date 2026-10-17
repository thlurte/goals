// ==============================================================================
// 🥋 Drill: AVX2 Aligned (_mm256_load_ps) vs Unaligned (_mm256_loadu_ps) Safety
//
// 📖 READING SOURCES:
// - Intel Intrinsics Guide: _mm256_load_ps vs _mm256_loadu_ps
// - Fog: Instruction Tables (Throughput and Latency of SIMD loads)
//
// 🎯 CORE LESSON:
// 1. `_mm256_load_ps` requires strict 32-byte alignment; passing unaligned address raises a General Protection Fault.
// 2. `_mm256_loadu_ps` tolerates unaligned addresses safely.
// 3. On modern CPUs, unaligned loads have equal throughput to aligned loads unless they cross a cache line boundary.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_28_day038_align_avx2_load_vs_loadu.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <immintrin.h>
#include <cassert>

int main() {
    std::cout << "--- Drill 28: AVX2 _mm256_load_ps vs _mm256_loadu_ps ---\n\n";

    alignas(32) float aligned_data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    float unaligned_data[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // Aligned load: Requires 32-byte alignment
    __m256 v_aligned = _mm256_load_ps(aligned_data);

    // Unaligned load: Works on offset + 1
    __m256 v_unaligned = _mm256_loadu_ps(&unaligned_data[1]);

    alignas(32) float out[8];
    _mm256_store_ps(out, _mm256_sub_ps(v_aligned, v_unaligned));

    for (int i = 0; i < 8; ++i) {
        assert(out[i] == 0.0f);
    }

    std::cout << "✓ Both aligned and unaligned AVX2 vectors matched identically.\n";
    std::cout << "\n✓ Drill 28 Passed: SIMD load semantics verified!\n";
    return 0;
}
