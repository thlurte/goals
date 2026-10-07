// ==============================================================================
// 🥋 Drill 17 (Day 34.8): Multithreading Mastery — C++20 `std::jthread` Worker Pool
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 9: Advanced Thread Management)
// - Herlihy & Shavit: The Art of Multiprocessor Programming (Ch 16: Work-Stealing)
//
// 🎯 CORE LESSON:
// 1. Modern C++20 `std::jthread` automatically joins on destruction and supports cooperative `std::stop_token`.
// 2. Thread-safe task queue with `std::mutex`, `std::condition_variable`, and RAII `std::unique_lock`.
// 3. Graceful shutdown: Waking all worker threads and draining pending vector distance tasks before termination.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra -pthread drill_17_day034_concurrency_thread_pool_work_stealing.cpp -o drill17 && ./drill17
// ==============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <cassert>
#include <atomic>

class ThreadPool {
public:
    explicit ThreadPool(size_t num_threads = std::thread::hardware_concurrency()) {
        for (size_t i = 0; i < num_threads; ++i) {
            workers_.emplace_back([this](std::stop_token stop_tok) {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex_);
                        cv_.wait(lock, [this, &stop_tok]() {
                            return stop_tok.stop_requested() || !tasks_.empty();
                        });

                        if (stop_tok.stop_requested() && tasks_.empty()) {
                            return; // Thread exits
                        }

                        task = std::move(tasks_.front());
                        tasks_.pop();
                    }
                    task(); // Execute task outside lock
                }
            });
        }
    }

    ~ThreadPool() noexcept {
        // Request stop on all jthreads
        for (auto& worker : workers_) {
            worker.request_stop();
        }
        cv_.notify_all();
        // jthreads automatically join on destruction!
    }

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    // TODO 1: Implement template task submission returning a std::future<ReturnType>
    // 1. Pack task into a std::packaged_task<ReturnType()> using std::make_shared
    // 2. Obtain future from packaged_task
    // 3. Enqueue lambda into tasks_ guarded by queue_mutex_
    // 4. Notify one worker thread via cv_.notify_one()
    // 5. Return the future
    template <typename F, typename... Args>
    auto submit(F&& f, Args&&... args) -> std::future<std::invoke_result_t<F, Args...>> {
        using ReturnType = std::invoke_result_t<F, Args...>;

        // [YOUR CODE HERE]
        return {};
    }

private:
    std::vector<std::jthread> workers_;
    std::queue<std::function<void()>> tasks_;
    std::mutex queue_mutex_;
    std::condition_variable cv_;
};

int main() {
    std::cout << "--- Drill 17: C++20 jthread Thread Pool & Futures ---\n\n";

    ThreadPool pool(4);
    constexpr int NUM_TASKS = 20;
    std::vector<std::future<int>> results;

    for (int i = 0; i < NUM_TASKS; ++i) {
        results.push_back(pool.submit([i]() {
            return i * i;
        }));
    }

    int sum = 0;
    for (int i = 0; i < NUM_TASKS; ++i) {
        sum += results[i].get();
    }

    std::cout << "Sum of squares (0..19): " << sum << " (Expected: 2470)\n";
    assert(sum == 2470);

    std::cout << "\n✓ Drill 17 Passed: ThreadPool and futures verified!\n";
    return 0;
}
