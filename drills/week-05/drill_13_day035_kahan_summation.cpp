// ==============================================================================
// 🥋 Drill 13 (Day 35.3): Numerical Stability — Kahan Compensated Accumulator
//
// 📖 READING SOURCES:
// - William Kahan (1965) / IEEE 754 Floating-Point Error Analysis
//
// 🎯 CORE LESSON:
// 1. Catastrophic cancellation & precision loss:
//    Adding tiny float numbers (e.g. 0.0001) to a large running accumulator (e.g. 10^6)
//    discards low mantissa bits.
// 2. Kahan Compensation Algorithm:
//    Uses a secondary variable `c` to catch lost low-order bits and feed them into the next addition.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_13_day035_kahan_summation.cpp -o drill13 && ./drill13
// ==============================================================================

#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>

// Naive accumulation (loses precision)
float naive_sum(const std::vector<float>& data) {
    float sum{0.0f};
    for (float x : data) sum += x;
    return sum;
}

// TODO 1: Implement Kahan compensated summation
// Algorithm:
// 1. Initialize `sum = 0.0f` and `c = 0.0f` (lost-bit tracker)
// 2. For each element x:
//    y = x - c
//    t = sum + y
//    c = (t - sum) - y
//    sum = t
// 3. Return sum
float kahan_sum(const std::vector<float>& data) {
    // [YOUR CODE HERE]
    return 0.0f;
}

int main() {
    std::cout << "--- Drill 13: Kahan Numerical Compensation vs FP32 Drift ---\n\n";

    // 1 million small floats (0.0001f) added to 1,000,000.0f
    std::vector<float> data;
    data.push_back(1000000.0f);
    for (size_t i = 0; i < 1000000; ++i) {
        data.push_back(0.0001f);
    }
    // Exact mathematical sum: 1000000.0 + 100.0 = 1000100.0

    float naive = naive_sum(data);
    float kahan = kahan_sum(data);

    std::cout << std::setprecision(10);
    std::cout << "Theoretical Sum: 1000100.0000\n";
    std::cout << "Naive FP32 Sum:  " << naive << " (Lost precision!)\n";
    std::cout << "Kahan FP32 Sum:  " << kahan << " (Exact match!)\n";

    assert(kahan == 1000100.0f && "Kahan sum must retain full precision!");
    std::cout << "\n✓ Drill 13 Passed: Kahan numerical compensation verified!\n";
    return 0;
}
