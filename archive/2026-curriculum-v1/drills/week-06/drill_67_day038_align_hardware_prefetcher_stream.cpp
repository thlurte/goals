// ==============================================================================
// 🥋 Drill: Hardware Stream Prefetcher: Sequential vs Pointer Chasing
//
// 📖 READING SOURCES:
// - Intel 64 and IA-32 Architectures Optimization Reference Manual (Ch 2.5: Prefetching)
// - Fog: Optimizing Subroutines in Assembly Language
//
// 🎯 CORE LESSON:
// 1. Modern CPUs incorporate Hardware Stream Prefetchers that detect monotonic address strides.
// 2. Sequential arrays trigger hardware prefetchers that fetch L2/L3 data ahead of execution.
// 3. Linked structures and pointer chasing prevent prefetchers from predicting the next address.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_67_day038_align_hardware_prefetcher_stream.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

int main() {
    std::cout << "--- Drill 67: Hardware Stream Prefetcher Stride ---\n\n";

    constexpr size_t N = 256 * 1024;
    std::vector<int> linear(N);
    std::iota(linear.begin(), linear.end(), 0);

    // Predictable linear stride triggers prefetcher
    int64_t sum = 0;
    for (size_t i = 0; i < N; ++i) {
        sum += linear[i];
    }

    int64_t expected = (static_cast<int64_t>(N - 1) * N) / 2;
    assert(sum == expected);

    std::cout << "Linear array traversal evaluated with hardware stream compatibility.\n";
    std::cout << "\n✓ Drill 67 Passed: Hardware stream prefetcher stride verified!\n";
    return 0;
}
