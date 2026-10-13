// ==============================================================================
// 🥋 Drill: Multi-Phase Iteration Synchronization with C++20 std::barrier
//
// 📖 READING SOURCES:
// - C++20 Standard: <barrier>
// - Williams: C++ Concurrency in Action (2nd Ed)
//
// 🎯 CORE LESSON:
// 1. `std::barrier` synchronizes threads across cyclic iteration phases (unlike one-shot `std::latch`).
// 2. Executes a completion callback when all threads arrive before releasing them into the next phase.
// 3. Perfect for parallel $k$-Means clustering centroid update iterations.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_95_day038_concurrency_std_barrier_iterative_kmeans.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <barrier>
#include <thread>
#include <vector>
#include <cassert>

int main() {
    std::cout << "--- Drill 95: C++20 std::barrier Iteration Sync ---\n\n";

    constexpr int NumWorkers = 2;
    int phase_count = 0;

    auto on_phase_complete = [&]() noexcept {
        phase_count++;
    };

    std::barrier sync_point(NumWorkers, on_phase_complete);
    std::vector<std::thread> workers;

    for (int t = 0; t < NumWorkers; ++t) {
        workers.emplace_back([&] {
            // Iteration 1
            sync_point.arrive_and_wait();
            // Iteration 2
            sync_point.arrive_and_wait();
        });
    }

    for (auto& w : workers) w.join();
    assert(phase_count == 2);

    std::cout << "Both phases completed cleanly across all worker threads.\n";
    std::cout << "\n✓ Drill 95 Passed: std::barrier cyclic iteration sync verified!\n";
    return 0;
}
