// ==============================================================================
// 🥋 Drill: Lock-Free Concurrent Bitset via Atomic fetch_or
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action
// - Faiss: VisitedTable (HNSW search traversal)
//
// 🎯 CORE LESSON:
// 1. Vector search graph traversal (HNSW) requires a thread-safe `visited` bitset.
// 2. Word index: `idx / 64`; Bit mask: `1ULL << (idx % 64)`.
// 3. `fetch_or` marks a node visited lock-free and returns true if it was newly visited.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_91_day038_concurrency_concurrent_atomic_bitset.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <cassert>

class ConcurrentBitset {
public:
    explicit ConcurrentBitset(size_t num_bits)
        : words_((num_bits + 63) / 64) {
        for (auto& w : words_) w.store(0, std::memory_order_relaxed);
    }

    // Atomically set bit and return previous state
    bool test_and_set(size_t bit_idx) {
        size_t word_idx = bit_idx / 64;
        uint64_t mask = 1ULL << (bit_idx % 64);
        uint64_t prev = words_[word_idx].fetch_or(mask, std::memory_order_relaxed);
        return (prev & mask) != 0;
    }

private:
    std::vector<std::atomic<uint64_t>> words_;
};

int main() {
    std::cout << "--- Drill 91: Concurrent Bitset via Atomic fetch_or ---\n\n";

    ConcurrentBitset visited(1024);

    // First visit: returns false (was not previously set)
    bool already1 = visited.test_and_set(42);
    assert(already1 == false);

    // Second visit: returns true (was already set)
    bool already2 = visited.test_and_set(42);
    assert(already2 == true);

    std::cout << "\n✓ Drill 91 Passed: Lock-free atomic bitset test-and-set verified!\n";
    return 0;
}
