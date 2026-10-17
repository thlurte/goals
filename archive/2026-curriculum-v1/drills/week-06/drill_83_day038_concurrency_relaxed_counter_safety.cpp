// ==============================================================================
// 🥋 Drill: Safe Monotonic Counters with std::memory_order_relaxed
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 5.3.2: Relaxed ordering)
// - Preshing: Memory Ordering at Compile Time and Run Time
//
// 🎯 CORE LESSON:
// 1. `std::memory_order_relaxed` enforces atomicity and modification order on that single variable only.
// 2. Does NOT synchronize or order any other memory reads or writes.
// 3. Perfect for high-throughput metrics counters (e.g., total queries processed).
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_83_day038_concurrency_relaxed_counter_safety.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <cassert>

int main() {
    std::cout << "--- Drill 83: Relaxed Monotonic Metrics Counter ---\n\n";

    std::atomic<uint64_t> query_count{0};
    std::vector<std::thread> workers;

    for (int t = 0; t < 4; ++t) {
        workers.emplace_back([&] {
            for (int i = 0; i < 25000; ++i) {
                query_count.fetch_add(1, std::memory_order_relaxed);
            }
        });
    }

    for (auto& w : workers) w.join();
    assert(query_count.load(std::memory_order_relaxed) == 100000);

    std::cout << "Monotonic count reached 100000 with zero fencing overhead.\n";
    std::cout << "\n✓ Drill 83 Passed: memory_order_relaxed counter verified!\n";
    return 0;
}
