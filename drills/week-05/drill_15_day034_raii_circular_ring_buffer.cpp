// ==============================================================================
// 🥋 Drill 15 (Day 34.7): Modern C++ RAII — Lock-Free SPSC Circular Ring Buffer
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 7: Designing lock-free concurrent data structures)
// - Herlihy & Shavit: The Art of Multiprocessor Programming (Ch 3: Concurrent Objects)
//
// 🎯 CORE LESSON:
// 1. Single-Producer Single-Consumer (SPSC) lock-free ring buffer for vector ingestion streams.
// 2. Cache-line separation (`alignas(64)`) for head and tail atomic pointers to eliminate false sharing.
// 3. Acquire-Release memory orderings (`std::memory_order_acquire`, `std::memory_order_release`).
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra -pthread drill_15_day034_raii_circular_ring_buffer.cpp -o drill15 && ./drill15
// ==============================================================================

#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <cassert>
#include <cstdint>

template <typename T, size_t Capacity>
class SpscRingBuffer {
    static_assert((Capacity & (Capacity - 1)) == 0, "Capacity must be a power of 2 for fast modulo masking!");

public:
    SpscRingBuffer() : head_(0), tail_(0) {
        buffer_ = static_cast<T*>(std::aligned_alloc(64, Capacity * sizeof(T)));
        if (!buffer_) throw std::bad_alloc();
    }

    ~SpscRingBuffer() noexcept {
        if (buffer_) {
            std::free(buffer_);
            buffer_ = nullptr;
        }
    }

    SpscRingBuffer(const SpscRingBuffer&) = delete;
    SpscRingBuffer& operator=(const SpscRingBuffer&) = delete;

    // TODO 1: Implement lock-free push (Producer thread)
    // 1. Load head with relaxed memory order; load tail with acquire memory order
    // 2. Check if full: (head - tail) == Capacity (return false if full)
    // 3. Write item to buffer_[head & (Capacity - 1)]
    // 4. Store head + 1 with release memory order and return true
    bool push(const T& item) noexcept {
        // [YOUR CODE HERE]
        return false;
    }

    // TODO 2: Implement lock-free pop (Consumer thread)
    // 1. Load tail with relaxed memory order; load head with acquire memory order
    // 2. Check if empty: head == tail (return false if empty)
    // 3. Read item from buffer_[tail & (Capacity - 1)]
    // 4. Store tail + 1 with release memory order and return true
    bool pop(T& item) noexcept {
        // [YOUR CODE HERE]
        return false;
    }

    [[nodiscard]] size_t size() const noexcept {
        const size_t head = head_.load(std::memory_order_relaxed);
        const size_t tail = tail_.load(std::memory_order_relaxed);
        return head >= tail ? head - tail : 0;
    }

private:
    T* buffer_{nullptr};

    // Align head and tail to distinct 64-byte cache lines to prevent False Sharing (Cache Line Bouncing)
    alignas(64) std::atomic<size_t> head_{0};
    alignas(64) std::atomic<size_t> tail_{0};
};

int main() {
    std::cout << "--- Drill 15: SPSC Lock-Free Circular Ring Buffer ---\n\n";

    constexpr size_t BUFFER_SIZE = 1024;
    constexpr int NUM_ITEMS = 50000;
    SpscRingBuffer<int, BUFFER_SIZE> ring;

    // Multi-threaded Producer-Consumer test
    std::thread producer([&]() {
        for (int i = 0; i < NUM_ITEMS; ++i) {
            while (!ring.push(i)) {
                std::this_thread::yield();
            }
        }
    });

    std::vector<int> consumed;
    consumed.reserve(NUM_ITEMS);

    std::thread consumer([&]() {
        int val = 0;
        for (int i = 0; i < NUM_ITEMS; ++i) {
            while (!ring.pop(val)) {
                std::this_thread::yield();
            }
            consumed.push_back(val);
        }
    });

    producer.join();
    consumer.join();

    assert(consumed.size() == NUM_ITEMS);
    for (int i = 0; i < NUM_ITEMS; ++i) {
        assert(consumed[i] == i);
    }

    std::cout << "✓ Successfully streamed " << NUM_ITEMS << " elements across threads without locks or data races!\n";
    std::cout << "\n✓ Drill 15 Passed: Lock-free SPSC circular buffer verified!\n";
    return 0;
}
