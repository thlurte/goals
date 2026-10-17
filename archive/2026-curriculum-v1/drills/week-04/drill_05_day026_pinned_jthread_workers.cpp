// ==============================================================================
// 🥋 Drill 05 (Week 04 / Day 026): Fedor Pikus Ch 6 — Modern C++20 `std::jthread` Worker Pool
//
// 📖 READING SOURCES:
// - Fedor Pikus: The Art of Writing Efficient Programs (Ch 6: Thread Pools)
//
// 🎯 CORE LESSON:
// 1. C++20 `std::jthread`:
//    Automatically joins upon destruction, eliminating thread leak bugs and dangling threads.
// 2. Multi-threaded batch query scanning.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_05_day026_pinned_jthread_workers.cpp -o drill05 && ./drill05
// ==============================================================================

#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <cassert>

int main() {
    std::cout << "--- Week 04 Drill 05: Modern C++20 std::jthread Workers ---\n\n";

    constexpr size_t NUM_THREADS = 4;
    std::atomic<uint32_t> completed_tasks{0};

    {
        std::vector<std::jthread> workers;
        workers.reserve(NUM_THREADS);

        for (size_t i = 0; i < NUM_THREADS; ++i) {
            workers.emplace_back([&completed_tasks, i]() {
                completed_tasks.fetch_add(1, std::memory_order_relaxed);
            });
        }
        // std::jthread automatically joins here upon exiting the scope!
    }

    std::cout << "Completed Tasks: " << completed_tasks.load() << "\n";
    assert(completed_tasks.load() == NUM_THREADS);

    std::cout << "✓ std::jthread workers successfully spawned and auto-joined!\n";
    std::cout << "\n✓ Week 04 Drill 05 Passed Successfully!\n";
    return 0;
}
