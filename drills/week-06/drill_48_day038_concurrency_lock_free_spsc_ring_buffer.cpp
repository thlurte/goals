// ==============================================================================
// 🥋 Drill: Lock-Free Single-Producer Single-Consumer (SPSC) Circular Queue
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 7.2: Lock-free queues)
// - Folly: ProducerConsumerQueue.h
//
// 🎯 CORE LESSON:
// 1. An SPSC queue requires NO mutexes when head and tail pointers are atomic.
// 2. Head pointer is modified exclusively by consumer; tail pointer exclusively by producer.
// 3. Uses `acquire-release` memory orderings to safely synchronize data transfers.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_48_day038_concurrency_lock_free_spsc_ring_buffer.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <cassert>

template <typename T, size_t Capacity>
class SPSCRingBuffer {
public:
    SPSCRingBuffer() : head_(0), tail_(0) {}

    bool push(const T& val) {
        size_t current_tail = tail_.load(std::memory_order_relaxed);
        size_t next_tail = (current_tail + 1) % Capacity;
        if (next_tail == head_.load(std::memory_order_acquire)) {
            return false; // Queue is full
        }
        buffer_[current_tail] = val;
        tail_.store(next_tail, std::memory_order_release);
        return true;
    }

    bool pop(T& val) {
        size_t current_head = head_.load(std::memory_order_relaxed);
        if (current_head == tail_.load(std::memory_order_acquire)) {
            return false; // Queue is empty
        }
        val = buffer_[current_head];
        head_.store((current_head + 1) % Capacity, std::memory_order_release);
        return true;
    }

private:
    T buffer_[Capacity];
    alignas(64) std::atomic<size_t> head_;
    alignas(64) std::atomic<size_t> tail_;
};

int main() {
    std::cout << "--- Drill 48: Lock-Free SPSC Ring Buffer ---\n\n";

    SPSCRingBuffer<int, 128> ring;
    constexpr int N = 10000;

    std::thread producer([&] {
        for (int i = 0; i < N; ++i) {
            while (!ring.push(i)) std::this_thread::yield();
        }
    });

    std::thread consumer([&] {
        int expected = 0;
        int val = 0;
        while (expected < N) {
            if (ring.pop(val)) {
                assert(val == expected);
                expected++;
            } else {
                std::this_thread::yield();
            }
        }
    });

    producer.join();
    consumer.join();

    std::cout << "Streamed " << N << " items lock-free through SPSC ring buffer.\n";
    std::cout << "\n✓ Drill 48 Passed: Lock-free SPSC queue verified!\n";
    return 0;
}
