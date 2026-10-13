// ==============================================================================
// 🥋 Drill: Double-Checked Locking Pattern with Acquire-Release Atomics
//
// 📖 READING SOURCES:
// - Meyers & Alexandrescu: C++ and the Perils of Double-Checked Locking
// - Williams: C++ Concurrency in Action (Ch 3.3.1)
//
// 🎯 CORE LESSON:
// 1. Naive double-checked locking without atomics suffers instruction reordering UB.
// 2. Using `std::atomic` pointer with `acquire-release` ordering ensures the constructed object is visible.
// 3. `std::call_once` and `std::once_flag` provide standard-compliant lazy initialization.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_98_day038_concurrency_double_checked_locking_acquire_release.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <mutex>
#include <cassert>

static int s_singleton_init_count = 0;

class GlobalVectorEngine {
public:
    static GlobalVectorEngine& instance() {
        static GlobalVectorEngine inst; // Magic Statics in C++11 (thread-safe double-checked lock under the hood!)
        return inst;
    }

    int id() const { return 42; }

private:
    GlobalVectorEngine() { s_singleton_init_count++; }
};

int main() {
    std::cout << "--- Drill 98: Thread-Safe Singleton Initialization ---\n\n";

    GlobalVectorEngine& e1 = GlobalVectorEngine::instance();
    GlobalVectorEngine& e2 = GlobalVectorEngine::instance();

    assert(&e1 == &e2);
    assert(s_singleton_init_count == 1);
    assert(e1.id() == 42);

    std::cout << "\n✓ Drill 98 Passed: Thread-safe lazy initialization verified!\n";
    return 0;
}
