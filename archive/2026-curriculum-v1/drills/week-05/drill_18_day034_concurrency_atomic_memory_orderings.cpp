// ==============================================================================
// 🥋 Drill 18 (Day 34.9): Multithreading Mastery — Atomic Memory Orderings & CAS
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 5: The C++ memory model and operations on atomic types)
// - Boehm: "Threads Cannot be Implemented as a Library" (PLDI 2005)
//
// 🎯 CORE LESSON:
// 1. Sequentially Consistent (`std::memory_order_seq_cst`) vs Acquire-Release (`acquire`/`release`) vs Relaxed (`relaxed`).
// 2. Lock-Free Compare-And-Swap (CAS) loops: `compare_exchange_weak` in a retry loop.
// 3. Lock-Free Treiber Stack: Push and Pop nodes concurrently without mutexes.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra -pthread drill_18_day034_concurrency_atomic_memory_orderings.cpp -o drill18 && ./drill18
// ==============================================================================

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <cassert>
#include <optional>

template <typename T>
class LockFreeStack {
    struct Node {
        T data;
        Node* next{nullptr};
        explicit Node(const T& val) : data(val), next(nullptr) {}
    };

public:
    LockFreeStack() : head_(nullptr) {}

    ~LockFreeStack() {
        // Drain remaining nodes
        Node* curr = head_.load(std::memory_order_relaxed);
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    LockFreeStack(const LockFreeStack&) = delete;
    LockFreeStack& operator=(const LockFreeStack&) = delete;

    // TODO 1: Implement lock-free push using compare_exchange_weak (CAS loop)
    // 1. Allocate new Node(val)
    // 2. Set new_node->next = head_.load(std::memory_order_relaxed)
    // 3. Loop: while (!head_.compare_exchange_weak(new_node->next, new_node,
    //                                              std::memory_order_release,
    //                                              std::memory_order_relaxed)) {}
    void push(const T& val) {
        // [YOUR CODE HERE]
    }

    // TODO 2: Implement lock-free pop using CAS loop
    // 1. Load curr_head = head_.load(std::memory_order_acquire)
    // 2. Loop: while (curr_head && !head_.compare_exchange_weak(curr_head, curr_head->next,
    //                                                           std::memory_order_acquire,
    //                                                           std::memory_order_relaxed)) {}
    // 3. If curr_head is null, return std::nullopt
    // 4. Extract data, delete curr_head, and return data
    std::optional<T> pop() {
        // [YOUR CODE HERE]
        return std::nullopt;
    }

private:
    std::atomic<Node*> head_{nullptr};
};

int main() {
    std::cout << "--- Drill 18: Lock-Free Treiber Stack & Atomic Memory Orderings ---\n\n";

    LockFreeStack<int> stack;
    constexpr int NUM_THREADS = 4;
    constexpr int OPS_PER_THREAD = 10000;

    std::vector<std::thread> producers;
    for (int t = 0; t < NUM_THREADS; ++t) {
        producers.emplace_back([&stack, t]() {
            for (int i = 0; i < OPS_PER_THREAD; ++i) {
                stack.push(t * OPS_PER_THREAD + i);
            }
        });
    }

    for (auto& t : producers) t.join();

    std::atomic<int> pop_count{0};
    std::vector<std::thread> consumers;
    for (int t = 0; t < NUM_THREADS; ++t) {
        consumers.emplace_back([&stack, &pop_count]() {
            for (int i = 0; i < OPS_PER_THREAD; ++i) {
                while (!stack.pop().has_value()) {
                    std::this_thread::yield();
                }
                pop_count.fetch_add(1, std::memory_order_relaxed);
            }
        });
    }

    for (auto& t : consumers) t.join();

    assert(pop_count.load() == NUM_THREADS * OPS_PER_THREAD);
    std::cout << "✓ Concurrent push/pop of " << pop_count.load() << " elements verified without mutexes!\n";

    std::cout << "\n✓ Drill 18 Passed: Lock-free Treiber stack operational!\n";
    return 0;
}
