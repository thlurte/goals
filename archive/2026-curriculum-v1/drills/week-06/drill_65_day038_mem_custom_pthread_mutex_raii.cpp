// ==============================================================================
// 🥋 Drill: Bare-Metal RAII: Wrapping C pthread_mutex_t from First Principles
//
// 📖 READING SOURCES:
// - POSIX Threads Programming (pthread_mutex_lock/unlock)
// - Stroustrup: The C++ Programming Language (Ch 13: Resource Management)
//
// 🎯 CORE LESSON:
// 1. RAII was invented by Bjarne Stroustrup to solve exception-safe resource release.
// 2. The constructor calls `pthread_mutex_lock(&mtx)`, destructor calls `pthread_mutex_unlock(&mtx)`.
// 3. Guarantees the lock is released even if a function exits via early return or exception.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_65_day038_mem_custom_pthread_mutex_raii.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <pthread.h>
#include <cassert>

class PosixMutex {
public:
    PosixMutex() { pthread_mutex_init(&mtx_, nullptr); }
    ~PosixMutex() { pthread_mutex_destroy(&mtx_); }

    void lock() { pthread_mutex_lock(&mtx_); }
    void unlock() { pthread_mutex_unlock(&mtx_); }

    PosixMutex(const PosixMutex&) = delete;
    PosixMutex& operator=(const PosixMutex&) = delete;

private:
    pthread_mutex_t mtx_;
};

class PosixLockGuard {
public:
    explicit PosixLockGuard(PosixMutex& m) : mtx_(m) { mtx_.lock(); }
    ~PosixLockGuard() { mtx_.unlock(); }

    PosixLockGuard(const PosixLockGuard&) = delete;
    PosixLockGuard& operator=(const PosixLockGuard&) = delete;

private:
    PosixMutex& mtx_;
};

int main() {
    std::cout << "--- Drill 65: Bare-Metal pthread RAII LockGuard ---\n\n";

    PosixMutex mtx;
    int shared_val = 0;

    {
        PosixLockGuard guard(mtx);
        shared_val = 100;
    } // Mutex unlocked automatically

    assert(shared_val == 100);
    std::cout << "\n✓ Drill 65 Passed: Custom pthread RAII LockGuard verified!\n";
    return 0;
}
