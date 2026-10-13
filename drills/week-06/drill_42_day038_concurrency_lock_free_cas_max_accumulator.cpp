// ==============================================================================
// 🥋 Drill: Lock-Free CAS Running Maximum Accumulator
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 7: Designing lock-free concurrent data structures)
// - cppreference: std::atomic::compare_exchange_weak
//
// 🎯 CORE LESSON:
// 1. Compare-And-Swap (CAS) atomically updates memory if the current value matches expectations.
// 2. `compare_exchange_weak` is preferred inside retry loops because it can generate faster instructions on ARM/x86.
// 3. Enables lock-free tracking of maximum/minimum values without locking mutexes.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_42_day038_concurrency_lock_free_cas_max_accumulator.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <algorithm>
#include <thread>
#include <vector>
#include <cassert>

class LockFreeMax {
public:
    void update(int val) {
        int current = max_val_.load(std::memory_order_relaxed);
        while (val > current &&
               !max_val_.compare_exchange_weak(current, val,
                                               std::memory_order_release,
                                               std::memory_order_relaxed)) {
            // current is automatically updated on failure
        }
    }

    int get() const { return max_val_.load(std::memory_order_acquire); }

private:
    std::atomic<int> max_val_{0};
};

int main() {
    std::cout << "--- Drill 42: Lock-Free CAS Maximum Accumulator ---\n\n";

    LockFreeMax tracker;
    std::vector<std::thread> workers;

    for (int i = 0; i < 4; ++i) {
        workers.emplace_back([&, i] {
            for (int j = 1; j <= 1000; ++j) {
                tracker.update(i * 1000 + j);
            }
        });
    }

    for (auto& w : workers) w.join();
    assert(tracker.get() == 4000);

    std::cout << "Maximum observed correctly: " << tracker.get() << "\n";
    std::cout << "\n✓ Drill 42 Passed: Lock-free CAS loop verified!\n";
    return 0;
}
