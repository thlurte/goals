// ==============================================================================
// 🥋 Drill: Eliminating False Sharing with alignas(64) Padding
//
// 📖 READING SOURCES:
// - Ulrich Drepper: What Every Programmer Should Know About Memory
// - cppreference: std::hardware_destructive_interference_size
//
// 🎯 CORE LESSON:
// 1. `alignas(64)` forces each thread-local counter into its own isolated 64-byte cache line.
// 2. Eliminates cross-core cache invalidation traffic during concurrent writes.
// 3. Standardized in C++17 as `std::hardware_destructive_interference_size`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_44_day038_concurrency_false_sharing_elimination_alignas.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <thread>
#include <cstdint>
#include <cassert>

// Each counter is padded to its own dedicated 64-byte cache line
struct PaddedCounters {
    alignas(64) uint64_t counter0{0};
    alignas(64) uint64_t counter1{0};
};

int main() {
    std::cout << "--- Drill 44: Eliminating False Sharing via alignas(64) ---\n\n";

    PaddedCounters counters;
    uintptr_t addr0 = reinterpret_cast<uintptr_t>(&counters.counter0);
    uintptr_t addr1 = reinterpret_cast<uintptr_t>(&counters.counter1);

    std::cout << "Padded addr0: 0x" << std::hex << addr0 << "\n";
    std::cout << "Padded addr1: 0x" << addr1 << std::dec << "\n";

    // Verification: Counters are on distinct cache lines
    assert(addr0 / 64 != addr1 / 64 && "Padded counters must be on distinct cache lines!");

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

    std::cout << "\n✓ Drill 44 Passed: False sharing eliminated with 64-byte padding!\n";
    return 0;
}
