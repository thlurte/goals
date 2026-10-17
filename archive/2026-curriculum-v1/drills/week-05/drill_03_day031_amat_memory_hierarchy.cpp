// ==============================================================================
// 🥋 Drill 03 (Day 31.3): H&P §2.1–2.2 — Memory Hierarchy & AMAT Modeling
//
// 📖 READING SOURCES:
// - Hennessy & Patterson: Computer Architecture (6th Ed, §2.1–2.2)
//
// 🎯 CORE LESSON:
// 1. Average Memory Access Time formula:
//    AMAT = Hit_Time_L1 + (Miss_Rate_L1 * Miss_Penalty_L1)
// 2. Recursive Miss Penalty:
//    Miss_Penalty_L1 = Hit_Time_L2 + (Miss_Rate_L2 * (Hit_Time_L3 + Miss_Rate_L3 * DRAM_Latency))
// 3. Why Quantization accelerates vector search:
//    Fitting vectors into L1/L2 drops cache miss rates by up to 10x, avoiding DRAM latency stalls.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_03_day031_amat_memory_hierarchy.cpp -o drill03 && ./drill03
// ==============================================================================

#include <iostream>
#include <cassert>

struct CacheHierarchy {
    double l1_hit_cycles{4.0};         // L1 cache hit: 4 cycles
    double l1_miss_rate{0.05};         // L1 miss rate: 5%
    double l2_hit_cycles{14.0};        // L2 cache hit: 14 cycles
    double l2_miss_rate{0.20};         // L2 miss rate: 20%
    double l3_hit_cycles{50.0};        // L3 cache hit: 50 cycles
    double l3_miss_rate{0.50};         // L3 miss rate: 50%
    double dram_latency_cycles{200.0}; // Main memory: 200 cycles
};

// TODO 1: Implement the recursive AMAT calculation
// Work backwards from DRAM -> L3 -> L2 -> L1
constexpr double calculate_amat(const CacheHierarchy& c) {
    // [YOUR CODE HERE]
    return 0.0;
}

int main() {
    std::cout << "--- Drill 03: H&P AMAT Memory Hierarchy Calculator ---\n\n";

    constexpr CacheHierarchy config{};
    constexpr double amat = calculate_amat(config);

    std::cout << "Calculated AMAT: " << amat << " CPU cycles\n";

    // Expected:
    // L3 Penalty = 50 + (0.50 * 200) = 150 cycles
    // L2 Penalty = 14 + (0.20 * 150) = 44 cycles
    // AMAT = 4 + (0.05 * 44) = 6.2 cycles
    assert(amat >= 6.199 && amat <= 6.201 && "AMAT must equal 6.2 cycles!");

    std::cout << "✓ Drill 03 Passed: AMAT memory hierarchy modeling verified!\n";
    return 0;
}
