// ==============================================================================
// 🥋 Drill: Memory Ordering: Relaxed vs Sequential Consistency
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 5.3: Memory orders)
// - Boehm & Adve: Foundations of the C++ Concurrency Memory Model
//
// 🎯 CORE LESSON:
// 1. `std::memory_order_seq_cst` (default) enforces a globally consistent execution order across all threads.
// 2. `std::memory_order_relaxed` enforces atomicity only, with no synchronization or ordering constraints.
// 3. Use `relaxed` for isolated counters where other memory operations do not depend on the counter's state.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_45_day038_concurrency_relaxed_vs_seq_cst_ordering.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <cassert>

int main() {
    std::cout << "--- Drill 45: Relaxed vs Seq_Cst Memory Ordering ---\n\n";

    std::atomic<int> relaxed_counter{0};
    std::vector<std::thread> threads;

    for (int i = 0; i < 4; ++i) {
        threads.emplace_back([&] {
            for (int j = 0; j < 10000; ++j) {
                // Relaxed is sufficient for monotonic metrics
                relaxed_counter.fetch_add(1, std::memory_order_relaxed);
            }
        });
    }

    for (auto& t : threads) t.join();
    assert(relaxed_counter.load(std::memory_order_relaxed) == 40000);

    std::cout << "Relaxed counter verified: " << relaxed_counter.load() << "\n";
    std::cout << "\n✓ Drill 45 Passed: memory_order_relaxed atomicity verified!\n";
    return 0;
}
