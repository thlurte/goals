// ==============================================================================
// 🥋 Drill: Lock-Free Treiber Stack with CAS
//
// 📖 READING SOURCES:
// - Treiber: Systems Programming: Coping with Parallelism (1986)
// - Williams: C++ Concurrency in Action (Ch 7.2: Lock-free stack)
//
// 🎯 CORE LESSON:
// 1. The Treiber Stack manages a singly-linked list using an atomic head pointer.
// 2. Push: `new_node->next = head; while (!head.compare_exchange_weak(new_node->next, new_node))`.
// 3. Wait-free for pushes; lock-free for concurrent operations without any mutexes.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_85_day038_concurrency_lock_free_treiber_stack.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <cassert>

template <typename T>
class TreiberStack {
    struct Node {
        T data;
        Node* next;
        explicit Node(const T& d) : data(d), next(nullptr) {}
    };

public:
    TreiberStack() : head_(nullptr) {}

    void push(const T& val) {
        Node* new_node = new Node(val);
        new_node->next = head_.load(std::memory_order_relaxed);
        while (!head_.compare_exchange_weak(new_node->next, new_node,
                                            std::memory_order_release,
                                            std::memory_order_relaxed)) {
        }
    }

    bool pop(T& val) {
        Node* old_head = head_.load(std::memory_order_acquire);
        while (old_head && !head_.compare_exchange_weak(old_head, old_head->next,
                                                        std::memory_order_release,
                                                        std::memory_order_acquire)) {
        }
        if (!old_head) return false;
        val = old_head->data;
        delete old_head;
        return true;
    }

private:
    std::atomic<Node*> head_;
};

int main() {
    std::cout << "--- Drill 85: Lock-Free Treiber Stack ---\n\n";

    TreiberStack<int> stack;
    constexpr int ItemsPerThread = 1000;
    std::vector<std::thread> producers;

    for (int t = 0; t < 4; ++t) {
        producers.emplace_back([&, t] {
            for (int i = 0; i < ItemsPerThread; ++i) {
                stack.push(t * 1000 + i);
            }
        });
    }

    for (auto& p : producers) p.join();

    int val = 0;
    int count = 0;
    while (stack.pop(val)) count++;

    assert(count == 4000);
    std::cout << "Popped all " << count << " items successfully.\n";
    std::cout << "\n✓ Drill 85 Passed: Lock-free Treiber stack operational!\n";
    return 0;
}
