// ==============================================================================
// 🥋 Drill: Data Race (UB) vs Race Condition (Logical Invariant Violation)
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 3.1: Problems with sharing data)
// - Boehm: Threads Cannot be Implemented as a Library
//
// 🎯 CORE LESSON:
// 1. A Data Race is two concurrent accesses to the same memory location, at least one write, without synchronization -> **UB**.
// 2. A Race Condition is a flaw in program logic where timing affects correctness, even with mutexes.
// 3. All data races must be eliminated using `std::atomic` or mutexes.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_81_day038_concurrency_data_race_vs_race_condition.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <thread>
#include <cassert>

int main() {
    std::cout << "--- Drill 81: Data Race Prevention with std::atomic ---\n\n";

    // Standard compliant: std::atomic prevents Data Race UB
    std::atomic<int> counter{0};

    std::thread t1([&] {
        for (int i = 0; i < 10000; ++i) counter.fetch_add(1, std::memory_order_relaxed);
    });

    std::thread t2([&] {
        for (int i = 0; i < 10000; ++i) counter.fetch_add(1, std::memory_order_relaxed);
    });

    t1.join();
    t2.join();

    assert(counter.load() == 20000);
    std::cout << "Counter safely updated without data races: " << counter.load() << "\n";

    std::cout << "\n✓ Drill 81 Passed: Data race UB eliminated with std::atomic!\n";
    return 0;
}
