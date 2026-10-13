// ==============================================================================
// 🥋 Drill: User-Space TTAS Spinlock via std::atomic_flag
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 5.2.2: Operations on std::atomic_flag)
// - Herlihy & Shavit: The Art of Multiprocessor Programming (Ch 7: Spin Locks)
//
// 🎯 CORE LESSON:
// 1. `std::atomic_flag` is guaranteed to be lock-free on all C++ platforms.
// 2. `test_and_set(memory_order_acquire)` spins until the lock is acquired.
// 3. `clear(memory_order_release)` unlocks the spinlock.
// 4. Extremely fast for ultra-short critical sections with low contention.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_41_day038_concurrency_spinlock_atomic_flag.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <cassert>

class Spinlock {
public:
    void lock() noexcept {
        while (flag_.test_and_set(std::memory_order_acquire)) {
            // Spin-wait hint (PAUSE on x86)
            #if defined(__x86_64__) || defined(_M_X64)
            __builtin_ia32_pause();
            #endif
        }
    }

    void unlock() noexcept {
        flag_.clear(std::memory_order_release);
    }

private:
    std::atomic_flag flag_ = ATOMIC_FLAG_INIT;
};

int main() {
    std::cout << "--- Drill 41: User-Space Spinlock with std::atomic_flag ---\n\n";

    Spinlock spin;
    int shared_val = 0;
    std::vector<std::thread> threads;

    for (int i = 0; i < 4; ++i) {
        threads.emplace_back([&] {
            for (int j = 0; j < 5000; ++j) {
                spin.lock();
                shared_val++;
                spin.unlock();
            }
        });
    }

    for (auto& t : threads) t.join();
    assert(shared_val == 20000);

    std::cout << "Spinlock protected shared_val up to " << shared_val << "\n";
    std::cout << "\n✓ Drill 41 Passed: User-space spinlock verified!\n";
    return 0;
}
