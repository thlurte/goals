// ==============================================================================
// 🥋 Drill: Deadlock Prevention with std::scoped_lock (Multi-Lock Acquisition)
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 3.2.5: Deadlock: the problem and solutions)
// - cppreference: std::scoped_lock (C++17)
//
// 🎯 CORE LESSON:
// 1. Acquiring multiple mutexes in different orders across threads causes ABBA deadlocks.
// 2. `std::scoped_lock` uses a deadlock-avoidance algorithm (like `std::lock`) to acquire all locks simultaneously.
// 3. Guarantees RAII release of all acquired locks on scope exit.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_38_day038_concurrency_deadlock_prevention_scoped_lock.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <mutex>
#include <thread>
#include <cassert>

struct Account {
    std::mutex mtx;
    int balance;
    explicit Account(int b) : balance(b) {}
};

void transfer(Account& from, Account& to, int amount) {
    // Acquires both mutexes deadlock-free regardless of parameter order
    std::scoped_lock lock(from.mtx, to.mtx);
    from.balance -= amount;
    to.balance += amount;
}

int main() {
    std::cout << "--- Drill 38: Deadlock Prevention with std::scoped_lock ---\n\n";

    Account a(1000), b(1000);

    std::thread t1([&] {
        for (int i = 0; i < 1000; ++i) transfer(a, b, 1);
    });

    std::thread t2([&] {
        for (int i = 0; i < 1000; ++i) transfer(b, a, 1);
    });

    t1.join();
    t2.join();

    assert(a.balance == 1000 && b.balance == 1000);
    std::cout << "Transfers finished concurrently without deadlocking.\n";
    std::cout << "\n✓ Drill 38 Passed: Multi-mutex scoped_lock verified!\n";
    return 0;
}
