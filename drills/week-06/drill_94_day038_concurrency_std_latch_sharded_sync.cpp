// ==============================================================================
// 🥋 Drill: Batch Synchronization with C++20 std::latch
//
// 📖 READING SOURCES:
// - C++20 Standard: <latch>
// - Williams: C++ Concurrency in Action (2nd Ed)
//
// 🎯 CORE LESSON:
// 1. `std::latch` is a downward counter initialized with count $N$.
// 2. Worker threads call `latch.count_down()` when finishing their shard.
// 3. `latch.wait()` blocks the main coordinator thread until all $N$ workers arrive.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_94_day038_concurrency_std_latch_sharded_sync.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <latch>
#include <thread>
#include <vector>
#include <cassert>

int main() {
    std::cout << "--- Drill 94: C++20 std::latch Batch Sync ---\n\n";

    constexpr int NumShards = 4;
    std::latch done_latch(NumShards);
    std::vector<int> results(NumShards, 0);

    for (int i = 0; i < NumShards; ++i) {
        std::thread([&, i] {
            results[i] = (i + 1) * 10;
            done_latch.count_down();
        }).detach();
    }

    // Wait until all 4 shards finish
    done_latch.wait();

    for (int i = 0; i < NumShards; ++i) {
        assert(results[i] == (i + 1) * 10);
    }

    std::cout << "All 4 shards synchronized via std::latch.\n";
    std::cout << "\n✓ Drill 94 Passed: std::latch batch coordination verified!\n";
    return 0;
}
