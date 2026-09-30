// ==============================================================================
// 🥋 Drill 24.1: Cache-Line Alignment & False Sharing Elimination (Pikus Ch 5)
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -std=c++20 day024_drill_01_cache_alignment.cpp -o drill24_1 && ./drill24_1
//
// CONTEXT:
// In multi-threaded vector ingestion/scanning, independent inverted list counters
// must never share the same 64-byte cache line.
//
// C++ SYSTEMS LESSON:
// - CPU caches operate in 64-byte lines.
// - Multiple threads writing to different variables in the SAME cache line causes
//   false sharing and severe performance degradation.
// - `alignas(64)` forces dedicated cache line isolation.
// ==============================================================================

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdint>
#include <cassert>

// TODO 1: Define an unaligned counter struct
// Should contain a single `volatile uint64_t value{0};`
struct UnalignedCounter {
    // [YOUR CODE HERE]
};

// TODO 2: Define a 64-byte cache-aligned counter struct using `alignas(64)`
// Should also contain `volatile uint64_t value{0};`
struct alignas(64) AlignedCounter {
    // [YOUR CODE HERE]
};

// TODO 3: Implement worker function: increment counter.value `iterations` times
template <typename T>
void worker_increment(T& counter, uint64_t iterations) {
    // [YOUR CODE HERE]
}

int main() {
    std::cout << "--- Drill 24.1: Cache Line Alignment & False Sharing Guard ---\n\n";

    // -------------------------------------------------------------------------
    // Part 1: Structural Size & Alignment Checks
    // -------------------------------------------------------------------------
    std::cout << "1. Memory Layout Comparison:\n";
    std::cout << "   UnalignedCounter: sizeof = " << sizeof(UnalignedCounter) 
              << " bytes, alignof = " << alignof(UnalignedCounter) << " bytes\n";
    std::cout << "   -> " << (64 / sizeof(UnalignedCounter)) 
              << " unaligned counters fit inside ONE 64-byte cache line (False Sharing Risk!)\n\n";

    std::cout << "   AlignedCounter  : sizeof = " << sizeof(AlignedCounter) 
              << " bytes, alignof = " << alignof(AlignedCounter) << " bytes\n";
    std::cout << "   -> Exactly 1 aligned counter per 64-byte cache line (Zero False Sharing!)\n\n";

    assert(alignof(AlignedCounter) == 64);
    assert(sizeof(AlignedCounter) == 64);

    // -------------------------------------------------------------------------
    // Part 2: Real-World Multi-Threaded Benchmark with std::jthread
    // -------------------------------------------------------------------------
    const size_t num_threads = 4;
    const uint64_t iterations = 100'000'000ULL;

    std::cout << "2. Running Multi-Threaded Benchmark (" << num_threads 
              << " threads x " << iterations << " iterations)...\n\n";

    // TODO 4: Measure Unaligned execution time using std::jthread
    // 1. Create a vector of `UnalignedCounter` with size `num_threads`.
    // 2. Start timer: auto start = std::chrono::high_resolution_clock::now();
    // 3. Inside a block `{ ... }`, launch `num_threads` jthreads calling worker_increment.
    // 4. End timer and calculate duration in milliseconds.
    long long unaligned_ms = 0;
    // [YOUR CODE HERE]


    // TODO 5: Measure Aligned execution time using std::jthread
    // Same as above, but with `AlignedCounter`.
    long long aligned_ms = 0;
    // [YOUR CODE HERE]


    // -------------------------------------------------------------------------
    // Output & Verification (Do not modify)
    // -------------------------------------------------------------------------
    std::cout << "   [Unaligned Test] Time: " << unaligned_ms << " ms\n";
    std::cout << "   [Aligned Test]   Time: " << aligned_ms << " ms\n\n";

    if (aligned_ms > 0) {
        double speedup = static_cast<double>(unaligned_ms) / static_cast<double>(aligned_ms);
        std::cout << "🚀 Speedup with alignas(64): " << speedup << "x faster!\n";
    }
    std::cout << "✓ Drill Passed: Cache isolation verified.\n";

    return 0;
}
