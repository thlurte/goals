// ==============================================================================
// 🥋 Drill: Compare-And-Swap: compare_exchange_weak vs compare_exchange_strong
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 5.2.4: Operations on std::atomic<T*>)
// - cppreference: compare_exchange_weak
//
// 🎯 CORE LESSON:
// 1. `compare_exchange_weak` may fail spuriously (even if value matches) on LL/SC architectures (ARM).
// 2. Inside a loop, `compare_exchange_weak` is strictly faster because it generates cheaper instructions.
// 3. `compare_exchange_strong` is required when NOT in a loop to guarantee no spurious failure.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_82_day038_concurrency_cas_weak_vs_strong.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <cassert>

int main() {
    std::cout << "--- Drill 82: compare_exchange_weak in Loops ---\n\n";

    std::atomic<int> val{10};

    // Correct pattern: compare_exchange_weak inside loop
    int expected = 10;
    int desired = 20;

    while (!val.compare_exchange_weak(expected, desired)) {
        // on failure, expected is updated to val.load()
    }

    assert(val.load() == 20);

    // One-shot check requires compare_exchange_strong
    expected = 20;
    bool success = val.compare_exchange_strong(expected, 30);
    assert(success == true);
    assert(val.load() == 30);

    std::cout << "\n✓ Drill 82 Passed: CAS weak and strong semantics verified!\n";
    return 0;
}
