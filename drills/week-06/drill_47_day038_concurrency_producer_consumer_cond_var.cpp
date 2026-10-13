// ==============================================================================
// 🥋 Drill: Bounded Blocking Queue with std::condition_variable
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 4: Synchronizing concurrent operations)
// - Stroustrup: The C++ Programming Language (Ch 41: Concurrency)
//
// 🎯 CORE LESSON:
// 1. `std::condition_variable` enables threads to sleep until notified by another thread.
// 2. `cv.wait(lock, predicate)` handles spurious wakeups by verifying the condition in a loop.
// 3. `notify_one()` awakens one waiting thread, while `notify_all()` awakens all.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_47_day038_concurrency_producer_consumer_cond_var.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <cassert>

class BoundedQueue {
public:
    explicit BoundedQueue(size_t capacity) : capacity_(capacity) {}

    void push(int val) {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_not_full_.wait(lock, [&] { return queue_.size() < capacity_; });
        queue_.push(val);
        cv_not_empty_.notify_one();
    }

    int pop() {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_not_empty_.wait(lock, [&] { return !queue_.empty(); });
        int val = queue_.front();
        queue_.pop();
        cv_not_full_.notify_one();
        return val;
    }

private:
    std::mutex mtx_;
    std::condition_variable cv_not_full_;
    std::condition_variable cv_not_empty_;
    std::queue<int> queue_;
    size_t capacity_;
};

int main() {
    std::cout << "--- Drill 47: Bounded Queue with Condition Variables ---\n\n";

    BoundedQueue q(2);
    int sum = 0;

    std::thread consumer([&] {
        for (int i = 0; i < 5; ++i) {
            sum += q.pop();
        }
    });

    std::thread producer([&] {
        for (int i = 1; i <= 5; ++i) {
            q.push(i);
        }
    });

    producer.join();
    consumer.join();

    assert(sum == 15);
    std::cout << "Produced and consumed sum: " << sum << "\n";
    std::cout << "\n✓ Drill 47 Passed: Condition variable bounded queue verified!\n";
    return 0;
}
