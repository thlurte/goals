// ==============================================================================
// 🥋 Drill: Atomic Bitwise Read-Modify-Write (fetch_and, fetch_or, fetch_xor)
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 5)
// - cppreference: std::atomic::fetch_and
//
// 🎯 CORE LESSON:
// 1. `std::atomic<uint32_t>` provides atomic bitwise operations: `fetch_and`, `fetch_or`, `fetch_xor`.
// 2. Translates to hardware atomic bit manipulation instructions on modern x86/ARM.
// 3. Allows multiple threads to update distinct status flags in a single state word lock-free.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_99_day038_concurrency_atomic_bitwise_operations.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <cstdint>
#include <cassert>

constexpr uint32_t FLAG_INDEXED  = 1 << 0;
constexpr uint32_t FLAG_TRAINED  = 1 << 1;
constexpr uint32_t FLAG_READONLY = 1 << 2;

int main() {
    std::cout << "--- Drill 99: Atomic Bitwise State Flags ---\n\n";

    std::atomic<uint32_t> state{0};

    // Set INDEXED and TRAINED
    state.fetch_or(FLAG_INDEXED | FLAG_TRAINED, std::memory_order_relaxed);
    assert((state.load() & FLAG_INDEXED) != 0);
    assert((state.load() & FLAG_TRAINED) != 0);
    assert((state.load() & FLAG_READONLY) == 0);

    // Clear TRAINED
    state.fetch_and(~FLAG_TRAINED, std::memory_order_relaxed);
    assert((state.load() & FLAG_TRAINED) == 0);

    // Toggle READONLY with XOR
    state.fetch_xor(FLAG_READONLY, std::memory_order_relaxed);
    assert((state.load() & FLAG_READONLY) != 0);

    std::cout << "\n✓ Drill 99 Passed: Atomic bitwise state operations verified!\n";
    return 0;
}
