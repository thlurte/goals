// ==============================================================================
// 🥋 Drill: Pinned Thread Worker Pool for Zero Cache-Bouncing
//
// 📖 READING SOURCES:
// - Love: Linux System Programming (Ch 6: Advanced Process Management: CPU Affinity)
// - Williams: C++ Concurrency in Action (Ch 9: Advanced thread management)
//
// 🎯 CORE LESSON:
// 1. Operating system thread migrations between CPU cores flush L1/L2 caches and collapse IPC.
// 2. Setting thread affinity (`pthread_setaffinity_np`) pins workers to dedicated physical cores.
// 3. Zero cache-bounce pinned worker pools form the foundation of high-throughput vector search engines.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_50_day038_concurrency_thread_pool_pinned_workers.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <pthread.h>
#include <cassert>

class PinnedThreadPool {
public:
    explicit PinnedThreadPool(size_t num_threads) : stop_(false) {
        for (size_t i = 0; i < num_threads; ++i) {
            workers_.emplace_back([this, i] {
                // Pin thread to CPU core i if available
                cpu_set_t cpuset;
                CPU_ZERO(&cpuset);
                CPU_SET(i % std::thread::hardware_concurrency(), &cpuset);
                pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queue_mtx_);
                        cv_.wait(lock, [this] { return stop_ || !tasks_.empty(); });
                        if (stop_ && tasks_.empty()) return;
                        task = std::move(tasks_.front());
                        tasks_.pop();
                    }
                    task();
                }
            });
        }
    }

    ~PinnedThreadPool() {
        {
            std::lock_guard<std::mutex> lock(queue_mtx_);
            stop_ = true;
        }
        cv_.notify_all();
        for (auto& w : workers_) w.join();
    }

    void enqueue(std::function<void()> task) {
        {
            std::lock_guard<std::mutex> lock(queue_mtx_);
            tasks_.push(std::move(task));
        }
        cv_.notify_one();
    }

private:
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> tasks_;
    std::mutex queue_mtx_;
    std::condition_variable cv_;
    bool stop_;
};

int main() {
    std::cout << "--- Drill 50: Pinned Thread Worker Pool ---\n\n";

    std::atomic<int> completed_tasks{0};
    {
        PinnedThreadPool pool(4);
        for (int i = 0; i < 20; ++i) {
            pool.enqueue([&completed_tasks] {
                completed_tasks.fetch_add(1, std::memory_order_relaxed);
            });
        }
    } // Pool destructor drains and joins all pinned workers

    assert(completed_tasks.load() == 20);
    std::cout << "All 20 tasks executed by pinned worker pool.\n";
    std::cout << "\n✓ Drill 50 Passed: Pinned thread worker pool fully operational!\n";
    return 0;
}
