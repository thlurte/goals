// ==============================================================================
// 🥋 Drill: Work-Stealing Deque: Local LIFO vs Remote FIFO Stealing
//
// 📖 READING SOURCES:
// - Chase & Lev: Dynamic Circular Work-Stealing Deque (SPAA 2005)
// - Williams: C++ Concurrency in Action (Ch 9.1: Work stealing)
//
// 🎯 CORE LESSON:
// 1. Worker thread pushes and pops from the bottom of its own deque in LIFO order (cache hot).
// 2. Idle thief threads steal tasks from the top in FIFO order (oldest task, cache cold).
// 3. Drastically mitigates task queue lock contention across thread pool workers.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_93_day038_concurrency_work_stealing_deque_basics.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <deque>
#include <mutex>
#include <cassert>

class ThreadWorkDeque {
public:
    void push_bottom(int task) {
        std::lock_guard<std::mutex> lock(mtx_);
        deque_.push_back(task); // LIFO bottom
    }

    bool pop_bottom(int& task) {
        std::lock_guard<std::mutex> lock(mtx_);
        if (deque_.empty()) return false;
        task = deque_.back();
        deque_.pop_back();
        return true;
    }

    bool steal_top(int& task) {
        std::lock_guard<std::mutex> lock(mtx_);
        if (deque_.empty()) return false;
        task = deque_.front(); // FIFO top steal
        deque_.pop_front();
        return true;
    }

private:
    std::mutex mtx_;
    std::deque<int> deque_;
};

int main() {
    std::cout << "--- Drill 93: Work-Stealing Deque Mechanics ---\n\n";

    ThreadWorkDeque q;
    q.push_bottom(1);
    q.push_bottom(2);
    q.push_bottom(3);

    // Thief steals oldest task from top (1)
    int stolen = 0;
    assert(q.steal_top(stolen) && stolen == 1);

    // Owner pops hottest task from bottom (3)
    int local = 0;
    assert(q.pop_bottom(local) && local == 3);

    std::cout << "\n✓ Drill 93 Passed: Work-stealing LIFO/FIFO mechanics verified!\n";
    return 0;
}
