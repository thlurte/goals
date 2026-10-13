// ==============================================================================
// 🥋 Drill: False Sharing on 64-Byte Cache Lines: Root Cause & Impact
//
// 📖 READING SOURCES:
// - Ulrich Drepper: What Every Programmer Should Know About Memory (Section 3.3.4: False Sharing)
// - Williams: C++ Concurrency in Action (Ch 7.2: Memory models and lock-free data structures)
//
// 🎯 CORE LESSON:
// 1. False sharing occurs when independent threads write to distinct variables residing on the same 64-byte cache line.
// 2. Causes the CPU cache coherence protocol (MESI/MOESI) to constantly invalidate the entire cache line across CPU cores.
// 3. Drastically collapses multi-threaded performance despite zero logical data races.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_43_day038_concurrency_false_sharing_demonstration.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <thread>
#include <cstdint>
#include <cassert>

// Both counters reside in the same 64-byte cache line!
struct UnpaddedCounters {
    uint64_t counter0{0};
    uint64_t counter1{0};
};

int main() {
    std::cout << "--- Drill 43: False Sharing Cache Line Collision ---\n\n";

    UnpaddedCounters counters;
    uintptr_t addr0 = reinterpret_cast<uintptr_t>(&counters.counter0);
    uintptr_t addr1 = reinterpret_cast<uintptr_t>(&counters.counter1);

    std::cout << "addr0: 0x" << std::hex << addr0 << "\n";
    std::cout << "addr1: 0x" << addr1 << std::dec << "\n";

    // Both addresses reside in the exact same 64-byte cache block
    assert(addr0 / 64 == addr1 / 64 && "Variables must share the same cache line to cause false sharing!");

    std::thread t1([&] {
        for (int i = 0; i < 500000; ++i) counters.counter0++;
    });

    std::thread t2([&] {
        for (int i = 0; i < 500000; ++i) counters.counter1++;
    });

    t1.join();
    t2.join();

    assert(counters.counter0 == 500000);
    assert(counters.counter1 == 500000);

    std::cout << "\n✓ Drill 43 Passed: False sharing cache collision detected!\n";
    return 0;
}
