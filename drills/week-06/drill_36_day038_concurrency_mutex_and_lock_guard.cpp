// ==============================================================================
// 🥋 Drill: std::mutex & std::lock_guard Critical Section Protection
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 3: Sharing data between threads)
// - Stroustrup: A Tour of C++ (Ch 15: Concurrency)
//
// 🎯 CORE LESSON:
// 1. `std::mutex` provides mutual exclusion to serialize access to shared memory.
// 2. `std::lock_guard` acquires the mutex in constructor and releases it in destructor (RAII lock).
// 3. Prevents data races and ensures locks are released even if exceptions are thrown.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_36_day038_concurrency_mutex_and_lock_guard.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <cassert>

class ThreadSafeCounter {
public:
    void increment() {
        std::lock_guard<std::mutex> lock(mtx_);
        count_++;
    }

    int value() const {
        std::lock_guard<std::mutex> lock(mtx_);
        return count_;
    }

private:
    mutable std::mutex mtx_;
    int count_{0};
};

int main() {
    std::cout << "--- Drill 36: std::mutex & std::lock_guard ---\n\n";

    ThreadSafeCounter counter;
    std::vector<std::thread> workers;

    for (int i = 0; i < 4; ++i) {
        workers.emplace_back([&] {
            for (int j = 0; j < 10000; ++j) {
                counter.increment();
            }
        });
    }

    for (auto& w : workers) w.join();
    assert(counter.value() == 40000);

    std::cout << "Counter safely incremented to " << counter.value() << " across 4 threads.\n";
    std::cout << "\n✓ Drill 36 Passed: Mutex synchronization verified!\n";
    return 0;
}
