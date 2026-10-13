// ==============================================================================
// 🥋 Drill: Hierarchical Mutex: Deadlock Elimination by Rank Enforcement
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 3.2.5: Hierarchical mutexes)
// - Coffman et al.: System Deadlocks (Circular wait condition)
//
// 🎯 CORE LESSON:
// 1. Enforcing a strict global ordering on lock acquisition mathematically prevents deadlock.
// 2. A thread holding a mutex of rank $R$ is only permitted to acquire locks of rank $< R$.
// 3. Throws an exception or fails an assertion if a reverse-order acquisition is attempted.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_97_day038_concurrency_lock_hierarchy_ranking.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <mutex>
#include <cassert>

thread_local uint32_t tl_current_rank = UINT32_MAX;

class HierarchicalMutex {
public:
    explicit HierarchicalMutex(uint32_t rank) : rank_(rank), prev_rank_(0) {}

    void lock() {
        assert(rank_ < tl_current_rank && "Lock hierarchy violation detected! Prevents deadlock.");
        mtx_.lock();
        prev_rank_ = tl_current_rank;
        tl_current_rank = rank_;
    }

    void unlock() {
        tl_current_rank = prev_rank_;
        mtx_.unlock();
    }

private:
    std::mutex mtx_;
    uint32_t rank_;
    uint32_t prev_rank_;
};

int main() {
    std::cout << "--- Drill 97: Hierarchical Mutex Rank Enforcement ---\n\n";

    HierarchicalMutex high_level(1000);
    HierarchicalMutex low_level(500);

    // Valid: Acquire high rank (1000) then lower rank (500)
    high_level.lock();
    low_level.lock();

    low_level.unlock();
    high_level.unlock();

    std::cout << "\n✓ Drill 97 Passed: Hierarchical lock ranking verified!\n";
    return 0;
}
