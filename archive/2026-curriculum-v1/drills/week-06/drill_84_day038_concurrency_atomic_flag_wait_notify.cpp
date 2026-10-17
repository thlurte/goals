// ==============================================================================
// 🥋 Drill: C++20 Atomic Notification via std::atomic_flag::wait and notify_one
//
// 📖 READING SOURCES:
// - C++20 Standard: [atomics.flag]
// - Williams: C++ Concurrency in Action (2nd Ed)
//
// 🎯 CORE LESSON:
// 1. C++20 introduced `atomic_flag::wait()` and `atomic_flag::notify_one()`.
// 2. Allows waiting threads to sleep on kernel futexes instead of burning 100% CPU spinning.
// 3. Combines the low footprint of `atomic_flag` with the sleep/wake efficiency of condition variables.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_84_day038_concurrency_atomic_flag_wait_notify.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <thread>
#include <cassert>

int main() {
    std::cout << "--- Drill 84: C++20 atomic_flag wait and notify ---\n\n";

    std::atomic_flag flag = ATOMIC_FLAG_INIT;
    bool worker_ran = false;

    std::thread worker([&] {
        // Wait until flag is set to true
        flag.wait(false);
        worker_ran = true;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    flag.test_and_set();
    flag.notify_one();

    worker.join();
    assert(worker_ran == true);

    std::cout << "\n✓ Drill 84 Passed: atomic_flag futex wait and notify verified!\n";
    return 0;
}
