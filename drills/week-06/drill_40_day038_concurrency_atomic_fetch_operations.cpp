// ==============================================================================
// 🥋 Drill: Lock-Free Metrics Counter via std::atomic Fetch Operations
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 5: The C++ memory model and operations on atomic types)
// - cppreference: std::atomic::fetch_add
//
// 🎯 CORE LESSON:
// 1. `std::atomic<T>` operations translate to lock-free CPU instructions (e.g., `LOCK XADD` on x86).
// 2. `fetch_add` and `fetch_sub` atomically modify integers without mutex locks.
// 3. Significantly lower overhead than mutexes for throughput and latency metrics counters.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_40_day038_concurrency_atomic_fetch_operations.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <cassert>

int main() {
    std::cout << "--- Drill 40: Lock-Free Atomic Fetch Operations ---\n\n";

    std::atomic<int64_t> total_queries{0};
    std::vector<std::thread> workers;

    for (int i = 0; i < 4; ++i) {
        workers.emplace_back([&] {
            for (int j = 0; j < 25000; ++j) {
                total_queries.fetch_add(1, std::memory_order_relaxed);
            }
        });
    }

    for (auto& w : workers) w.join();
    assert(total_queries.load() == 100000);

    std::cout << "Atomic counter reached 100,000 queries lock-free.\n";
    std::cout << "\n✓ Drill 40 Passed: Atomic fetch_add verified!\n";
    return 0;
}
