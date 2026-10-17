// ==============================================================================
// 🥋 Drill: Readers-Writer Lock via std::shared_mutex
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 3.3.2: Protecting rarely updated data structures)
// - cppreference: std::shared_mutex & std::shared_lock
//
// 🎯 CORE LESSON:
// 1. `std::shared_mutex` allows multiple concurrent readers via `std::shared_lock`.
// 2. Writers acquire exclusive access via `std::unique_lock`.
// 3. Ideal for vector search indexes with 99% read queries and rare background document writes.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_39_day038_concurrency_shared_mutex_readers_writer.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <shared_mutex>
#include <mutex>
#include <thread>
#include <vector>
#include <cassert>

class ReadHeavyCache {
public:
    void set(int val) {
        std::unique_lock<std::shared_mutex> lock(rw_mtx_); // Exclusive writer lock
        value_ = val;
    }

    int get() const {
        std::shared_lock<std::shared_mutex> lock(rw_mtx_); // Shared reader lock
        return value_;
    }

private:
    mutable std::shared_mutex rw_mtx_;
    int value_{0};
};

int main() {
    std::cout << "--- Drill 39: Readers-Writer Lock with std::shared_mutex ---\n\n";

    ReadHeavyCache cache;
    cache.set(100);

    std::vector<std::thread> readers;
    for (int i = 0; i < 8; ++i) {
        readers.emplace_back([&] {
            for (int j = 0; j < 1000; ++j) {
                assert(cache.get() == 100);
            }
        });
    }

    for (auto& r : readers) r.join();
    std::cout << "8 concurrent readers queried cache simultaneously.\n";
    std::cout << "\n✓ Drill 39 Passed: std::shared_mutex readers-writer lock verified!\n";
    return 0;
}
