// ==============================================================================
// 🥋 Drill: Fine-Grained Locking with std::unique_lock
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 3.2.4: Flexible locking with std::unique_lock)
// - Meyers: Effective Modern C++ (Item 39: Consider void futures for one-shot event communication)
//
// 🎯 CORE LESSON:
// 1. `std::unique_lock` offers flexible locking: deferred locking, premature unlocking, and timed locking.
// 2. Releasing locks before expensive compute or I/O minimizes lock contention.
// 3. Can be transferred (moved) into condition variables or other functions.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_37_day038_concurrency_unique_lock_fine_grained.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <mutex>
#include <cassert>

int main() {
    std::cout << "--- Drill 37: std::unique_lock Flexible Locking ---\n\n";

    std::mutex mtx;

    // Deferred locking
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
    assert(!lock.owns_lock());

    lock.lock();
    assert(lock.owns_lock());

    // Explicit early unlock to narrow critical section
    lock.unlock();
    assert(!lock.owns_lock());

    // Re-lock
    lock.lock();
    assert(lock.owns_lock());

    std::cout << "\n✓ Drill 37 Passed: std::unique_lock flexibility verified!\n";
    return 0;
}
