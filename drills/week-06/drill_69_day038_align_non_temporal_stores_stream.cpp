// ==============================================================================
// 🥋 Drill: Non-Temporal Stores (_mm256_stream_ps) for Cache Bypassing
//
// 📖 READING SOURCES:
// - Intel 64 and IA-32 Architectures Optimization Reference Manual (Section 7.6: Non-Temporal Stores)
// - Fog: Instruction Tables
//
// 🎯 CORE LESSON:
// 1. Standard stores fetch the target cache line from DRAM first ('Write-Allocate').
// 2. `_mm256_stream_ps` writes directly to RAM via Write-Combining buffers, bypassing L1/L2 caches.
// 3. Requires strict 32-byte alignment and an `_mm_sfence()` memory barrier when complete.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_69_day038_align_non_temporal_stores_stream.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <immintrin.h>
#include <cassert>

int main() {
    std::cout << "--- Drill 69: Non-Temporal Stream Stores (_mm256_stream_ps) ---\n\n";

    alignas(32) float output[8] = {0};
    __m256 val = _mm256_set1_ps(3.14159f);

    // Non-temporal write bypassing L1/L2 cache
    _mm256_stream_ps(output, val);

    // SFENCE drains the write-combining buffers to main memory
    _mm_sfence();

    for (int i = 0; i < 8; ++i) {
        assert(output[i] == 3.14159f);
    }

    std::cout << "\n✓ Drill 69 Passed: Non-temporal store and SFENCE verified!\n";
    return 0;
}
