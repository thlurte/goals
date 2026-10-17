// ==============================================================================
// 🥋 Drill 19 (Day 34.10): Multithreading Mastery — Hazard Pointers (Lock-Free Memory Reclamation)
//
// 📖 READING SOURCES:
// - Maged Michael: "Hazard Pointers: Safe Memory Reclamation for Lock-Free Objects" (IEEE TPDS 2004)
// - Herlihy & Shavit: The Art of Multiprocessor Programming (Ch 10: Memory Reclamation)
//
// 🎯 CORE LESSON:
// 1. The ABA Problem & Use-After-Free in Lock-Free structures: A reader thread reads a pointer,
//    while a writer thread pops, deletes, and re-allocates that address.
// 2. Hazard Pointer Mechanism: A reader publishes the node pointer it is currently reading
//    to a global/per-thread atomic hazard slot before accessing its fields.
// 3. Deferred Retirement: Nodes are retired to a retire-list; they are only freed when no active
//    thread's hazard pointer references that address.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra -pthread drill_19_day034_concurrency_hazard_pointers.cpp -o drill19 && ./drill19
// ==============================================================================

#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <cassert>
#include <algorithm>

constexpr size_t MAX_HAZARD_THREADS = 8;

struct HazardPointerDomain {
    std::atomic<void*> hazard_ptrs[MAX_HAZARD_THREADS];

    HazardPointerDomain() {
        for (size_t i = 0; i < MAX_HAZARD_THREADS; ++i) {
            hazard_ptrs[i].store(nullptr, std::memory_order_relaxed);
        }
    }

    void acquire(size_t thread_id, void* ptr) noexcept {
        hazard_ptrs[thread_id].store(ptr, std::memory_order_release);
    }

    void release(size_t thread_id) noexcept {
        hazard_ptrs[thread_id].store(nullptr, std::memory_order_release);
    }

    // Returns true if ANY active thread is currently protecting this pointer
    bool is_protected(void* ptr) const noexcept {
        for (size_t i = 0; i < MAX_HAZARD_THREADS; ++i) {
            if (hazard_ptrs[i].load(std::memory_order_acquire) == ptr) {
                return true;
            }
        }
        return false;
    }
};

static inline HazardPointerDomain g_hazard_domain;

template <typename T>
class SafeLockFreeStack {
    struct Node {
        T data;
        Node* next{nullptr};
        explicit Node(const T& val) : data(val), next(nullptr) {}
    };

public:
    SafeLockFreeStack() : head_(nullptr) {}

    ~SafeLockFreeStack() {
        // Reclaim all remaining nodes and retired nodes
        Node* curr = head_.load(std::memory_order_relaxed);
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        reclaim_retired_nodes();
    }

    void push(const T& val) {
        Node* new_node = new Node(val);
        new_node->next = head_.load(std::memory_order_relaxed);
        while (!head_.compare_exchange_weak(new_node->next, new_node,
                                            std::memory_order_release,
                                            std::memory_order_relaxed)) {}
    }

    // TODO 1: Implement hazard-pointer-protected lock-free pop
    // 1. Loop:
    //    a. curr_head = head_.load(std::memory_order_relaxed)
    //    b. if (!curr_head) return false;
    //    c. g_hazard_domain.acquire(thread_id, curr_head);
    //    d. if (curr_head != head_.load(std::memory_order_acquire)) continue; // head changed, retry
    //    e. if (head_.compare_exchange_weak(curr_head, curr_head->next, std::memory_order_release, std::memory_order_relaxed)) break;
    // 2. Extract result = curr_head->data
    // 3. g_hazard_domain.release(thread_id)
    // 4. Retire curr_head (or delete if not protected)
    bool pop(T& val, size_t thread_id) {
        // [YOUR CODE HERE]
        (void)val;
        (void)thread_id;
        return false;
    }

    void retire_node(Node* node) {
        retired_nodes_.push_back(node);
        if (retired_nodes_.size() >= 32) {
            reclaim_retired_nodes();
        }
    }

    void reclaim_retired_nodes() {
        auto it = retired_nodes_.begin();
        while (it != retired_nodes_.end()) {
            if (!g_hazard_domain.is_protected(*it)) {
                delete *it;
                it = retired_nodes_.erase(it);
            } else {
                ++it;
            }
        }
    }

private:
    std::atomic<Node*> head_{nullptr};
    thread_local static inline std::vector<Node*> retired_nodes_;
};

int main() {
    std::cout << "--- Drill 19: Safe Lock-Free Stack with Hazard Pointers ---\n\n";

    SafeLockFreeStack<int> stack;
    constexpr int NUM_THREADS = 4;
    constexpr int ITEMS_PER_THREAD = 5000;

    for (int i = 0; i < NUM_THREADS * ITEMS_PER_THREAD; ++i) {
        stack.push(i);
    }

    std::vector<std::thread> consumers;
    std::atomic<int> popped_total{0};

    for (size_t t = 0; t < NUM_THREADS; ++t) {
        consumers.emplace_back([&stack, &popped_total, t]() {
            int val = 0;
            for (int i = 0; i < ITEMS_PER_THREAD; ++i) {
                while (!stack.pop(val, t)) {
                    std::this_thread::yield();
                }
                popped_total.fetch_add(1, std::memory_order_relaxed);
            }
        });
    }

    for (auto& t : consumers) t.join();

    assert(popped_total.load() == NUM_THREADS * ITEMS_PER_THREAD);
    std::cout << "✓ Successfully popped " << popped_total.load() << " nodes safely with Hazard Pointers (0 use-after-free)!\n";

    std::cout << "\n✓ Drill 19 Passed: Hazard Pointer memory reclamation verified!\n";
    return 0;
}
