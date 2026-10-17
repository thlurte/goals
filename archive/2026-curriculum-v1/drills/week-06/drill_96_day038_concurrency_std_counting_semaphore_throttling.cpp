// ==============================================================================
// 🥋 Drill: Resource Throttling via C++20 std::counting_semaphore
//
// 📖 READING SOURCES:
// - C++20 Standard: <semaphore>
// - Dijkstra: Cooperating Sequential Processes (Semaphores)
//
// 🎯 CORE LESSON:
// 1. `std::counting_semaphore<N>` limits concurrent access to at most $N$ resources.
// 2. `acquire()` decrements internal counter, blocking if 0.
// 3. `release()` increments counter and unblocks waiting threads.
// 4. Ideal for throttling maximum concurrent disk read or GPU DMA requests.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_96_day038_concurrency_std_counting_semaphore_throttling.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>
#include <cassert>

int main() {
    std::cout << "--- Drill 96: std::counting_semaphore Throttling ---\n\n";

    // Permit at most 2 concurrent operations
    std::counting_semaphore<2> sem(2);
    std::atomic<int> concurrent_active{0};
    std::atomic<int> max_observed{0};

    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back([&] {
            sem.acquire();
            int current = ++concurrent_active;
            int prev_max = max_observed.load();
            while (current > prev_max && !max_observed.compare_exchange_weak(prev_max, current)) {}

            std::this_thread::sleep_for(std::chrono::milliseconds(2));
            --concurrent_active;
            sem.release();
        });
    }

    for (auto& t : threads) t.join();
    assert(max_observed.load() <= 2 && "Semaphore must throttle concurrent active threads to <= 2!");

    std::cout << "Max concurrent active observed: " << max_observed.load() << "\n";
    std::cout << "\n✓ Drill 96 Passed: std::counting_semaphore throttling verified!\n";
    return 0;
}
