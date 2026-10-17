// ==============================================================================
// 🥋 Drill 04 (Week 01 / Day 003): Fedor Pikus Ch 1–2 — Dead Code Elimination & Timers
//
// 📖 READING SOURCES:
// - Fedor Pikus: The Art of Writing Efficient Programs (Ch 1 & Ch 2: Performance Measurements)
//
// 🎯 CORE LESSON:
// 1. The Dead Code Elimination (DCE) Trap:
//    When compiling with `-O3`, if the return value of a benchmark loop is not consumed,
//    the compiler detects it as pure and deletes the entire loop (measuring 0.0 ns!).
// 2. Preventing DCE with Inline Assembly:
//    `asm volatile("" : "+r,m"(val) : : "memory");`
//    Tells the compiler that `val` is read and modified in an opaque way, forcing full computation.
// 3. High-Resolution Timing with `std::chrono::high_resolution_clock`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_04_day003_pikus_benchmark_dce.cpp -o drill04 && ./drill04
// ==============================================================================

#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <cassert>

// TODO 1: Implement DoNotOptimize to prevent compiler DCE
// Use inline assembly constraint "+r,m"
template <typename T>
inline void do_not_optimize(T& val) {
    #if defined(__GNUC__) || defined(__clang__)
    asm volatile("" : "+r,m"(val) : : "memory");
    #endif
}

// TODO 2: Measure execution time in nanoseconds of a function
template <typename Func>
uint64_t benchmark_nanoseconds(Func&& fn, size_t iterations) {
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < iterations; ++i) {
        fn();
    }
    auto end = std::chrono::high_resolution_clock::now();
    return static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
    );
}

int main() {
    std::cout << "--- Week 01 Drill 04: Pikus Ch 1–2 DCE Prevention & Benchmarking ---\n\n";

    constexpr size_t N = 10000;
    std::vector<float> vec(N, 1.0f);

    float sum{0.0f};
    uint64_t ns = benchmark_nanoseconds([&]() {
        sum = 0.0f;
        for (float x : vec) sum += x;
        do_not_optimize(sum); // Forces compiler to execute the loop!
    }, 1000);

    std::cout << "Computed Sum: " << sum << " (Expected: 10000.0)\n";
    std::cout << "1000 Iterations Time: " << ns << " ns\n";

    assert(sum == 10000.0f);
    assert(ns > 0 && "Benchmark must measure actual non-zero execution time!");

    std::cout << "\n✓ Week 01 Drill 04 Passed Successfully!\n";
    return 0;
}
