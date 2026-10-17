// ==============================================================================
// 🥋 Drill: Isolated Cache Lines in Circular Ring Buffers
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 7)
// - Ulrich Drepper: What Every Programmer Should Know About Memory
//
// 🎯 CORE LESSON:
// 1. Single-Producer Single-Consumer ring buffers have two hot variables: `head` and `tail`.
// 2. If `head` and `tail` reside on the same 64-byte cache line, producer writes invalidate consumer reads.
// 3. Padding each pointer with `alignas(64)` eliminates false sharing between producer and consumer.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_80_day038_align_cache_aligned_circular_buffer.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cassert>

struct IsolatedRingLayout {
    alignas(64) uint64_t head;
    alignas(64) uint64_t tail;
};

int main() {
    std::cout << "--- Drill 80: Isolated Cache-Line Circular Buffer Layout ---\n\n";

    IsolatedRingLayout ring;
    uintptr_t head_addr = reinterpret_cast<uintptr_t>(&ring.head);
    uintptr_t tail_addr = reinterpret_cast<uintptr_t>(&ring.tail);

    assert(head_addr % 64 == 0);
    assert(tail_addr % 64 == 0);
    assert(tail_addr - head_addr >= 64);

    std::cout << "Head address: 0x" << std::hex << head_addr << "\n";
    std::cout << "Tail address: 0x" << tail_addr << std::dec << "\n";

    std::cout << "\n✓ Drill 80 Passed: Producer/consumer cache lines completely isolated!\n";
    return 0;
}
