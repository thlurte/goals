// ==============================================================================
// 🥋 Drill: Writer-Preference Read-Write Lock (Starvation Prevention)
//
// 📖 READING SOURCES:
// - Courtois et al.: Concurrent Control with 'Readers' and 'Writers' (1971)
// - Williams: C++ Concurrency in Action
//
// 🎯 CORE LESSON:
// 1. Standard readers-writer locks often prioritize readers, causing background writers to starve indefinitely.
// 2. Writer-preference locks make new readers wait if there is a pending writer.
// 3. Crucial for vector databases where background document index flushes must not be starved by queries.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_88_day038_concurrency_writer_preference_rwlock.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <cassert>

class WriterPrefRWLock {
public:
    void lock_read() {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_read_.wait(lock, [this] { return writers_active_ == 0 && writers_waiting_ == 0; });
        readers_active_++;
    }

    void unlock_read() {
        std::unique_lock<std::mutex> lock(mtx_);
        readers_active_--;
        if (readers_active_ == 0 && writers_waiting_ > 0) {
            cv_write_.notify_one();
        }
    }

    void lock_write() {
        std::unique_lock<std::mutex> lock(mtx_);
        writers_waiting_++;
        cv_write_.wait(lock, [this] { return readers_active_ == 0 && writers_active_ == 0; });
        writers_waiting_--;
        writers_active_++;
    }

    void unlock_write() {
        std::unique_lock<std::mutex> lock(mtx_);
        writers_active_--;
        if (writers_waiting_ > 0) {
            cv_write_.notify_one();
        } else {
            cv_read_.notify_all();
        }
    }

private:
    std::mutex mtx_;
    std::condition_variable cv_read_;
    std::condition_variable cv_write_;
    int readers_active_{0};
    int writers_active_{0};
    int writers_waiting_{0};
};

int main() {
    std::cout << "--- Drill 88: Writer-Preference RWLock ---\n\n";

    WriterPrefRWLock rw;
    int shared_val = 0;

    rw.lock_write();
    shared_val = 999;
    rw.unlock_write();

    rw.lock_read();
    assert(shared_val == 999);
    rw.unlock_read();

    std::cout << "\n✓ Drill 88 Passed: Writer-preference lock operational!\n";
    return 0;
}
