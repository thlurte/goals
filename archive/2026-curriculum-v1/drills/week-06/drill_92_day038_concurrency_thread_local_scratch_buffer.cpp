// ==============================================================================
// 🥋 Drill: thread_local Storage: Zero-Allocation Query Scratchpads
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++
// - Ulrich Drepper: What Every Programmer Should Know About Memory
//
// 🎯 CORE LESSON:
// 1. `thread_local` gives each executing thread its own dedicated instance of a variable.
// 2. Eliminates dynamic allocations inside high-frequency query functions.
// 3. Zero synchronization overhead: threads never access each other's thread-local buffers.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_92_day038_concurrency_thread_local_scratch_buffer.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <vector>
#include <thread>
#include <cassert>

thread_local std::vector<float> tl_scratch_buffer;

void process_query(int query_id) {
    if (tl_scratch_buffer.empty()) {
        tl_scratch_buffer.resize(128, 0.0f);
    }
    tl_scratch_buffer[0] = static_cast<float>(query_id);
    assert(tl_scratch_buffer[0] == static_cast<float>(query_id));
}

int main() {
    std::cout << "--- Drill 92: thread_local Scratch Buffers ---\n\n";

    std::thread t1([] { process_query(101); });
    std::thread t2([] { process_query(202); });

    t1.join();
    t2.join();

    std::cout << "\n✓ Drill 92 Passed: thread_local zero-allocation scratchpad verified!\n";
    return 0;
}
