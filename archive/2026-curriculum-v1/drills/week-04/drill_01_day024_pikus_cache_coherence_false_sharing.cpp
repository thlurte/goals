// ==============================================================================
// 🥋 Drill 01 (Week 04 / Day 024): Fedor Pikus Ch 5 — Cache Coherence & False Sharing
//
// 📖 READING SOURCES:
// - Fedor Pikus: The Art of Writing Efficient Programs (Ch 5: Concurrency & False Sharing)
//
// 🎯 CORE LESSON:
// 1. MESI Cache Coherence Protocol:
//    When two threads write to variables residing on the same 64-byte cache line,
//    cache lines ping-pong across CPU cores (Invalidate -> Read Shared -> Invalidate),
//    causing massive slowdowns.
// 2. Cache-Line Padding:
//    Using `alignas(64)` pads thread-local accumulators to distinct cache lines.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_01_day024_pikus_cache_coherence_false_sharing.cpp -o drill01 && ./drill01
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cassert>

// Thread-local counter padded to exactly 1 cache line (64 bytes)
struct alignas(64) PaddedCounter {
    uint64_t count{0};
};

int main() {
    std::cout << "--- Week 04 Drill 01: Cache Coherence & False Sharing Prevention ---\n\n";

    PaddedCounter counters[4];

    // Verify each counter sits on a distinct 64-byte boundary
    for (size_t i = 0; i < 4; ++i) {
        uintptr_t addr = reinterpret_cast<uintptr_t>(&counters[i]);
        std::cout << "Counter " << i << " Address: " << (void*)addr << "\n";
        assert(addr % 64 == 0 && "Must be aligned to 64-byte cache line!");
    }

    ptrdiff_t diff = reinterpret_cast<char*>(&counters[1]) - reinterpret_cast<char*>(&counters[0]);
    assert(diff >= 64 && "Distance between counters must be at least 64 bytes to prevent false sharing!");

    std::cout << "\n✓ Week 04 Drill 01 Passed Successfully!\n";
    return 0;
}
