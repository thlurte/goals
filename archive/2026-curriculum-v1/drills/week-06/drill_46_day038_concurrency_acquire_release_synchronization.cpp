// ==============================================================================
// 🥋 Drill: Acquire-Release Synchronization (Producer-Consumer Publishing)
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 5.3.3: Acquire-release ordering)
// - Preshing on Programming: The Acquire and Release Semantics
//
// 🎯 CORE LESSON:
// 1. Store with `memory_order_release` prevents previous writes from moving after the store.
// 2. Load with `memory_order_acquire` prevents subsequent reads from moving before the load.
// 3. Establishes a happens-before relationship between producer and consumer threads without full fences.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_46_day038_concurrency_acquire_release_synchronization.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <thread>
#include <string>
#include <cassert>

std::string g_payload;
std::atomic<bool> g_ready{false};

void producer() {
    g_payload = "precomputed_vector_graph_index";
    // Release barrier: makes g_payload write visible before ready flag is set
    g_ready.store(true, std::memory_order_release);
}

void consumer() {
    // Acquire barrier: guarantees that reads following this see writes before release
    while (!g_ready.load(std::memory_order_acquire)) {
        std::this_thread::yield();
    }
    assert(g_payload == "precomputed_vector_graph_index");
}

int main() {
    std::cout << "--- Drill 46: Acquire-Release Synchronization ---\n\n";

    std::thread t2(consumer);
    std::thread t1(producer);

    t1.join();
    t2.join();

    std::cout << "Payload safely transmitted via acquire-release ordering.\n";
    std::cout << "\n✓ Drill 46 Passed: Happens-before relationship verified!\n";
    return 0;
}
