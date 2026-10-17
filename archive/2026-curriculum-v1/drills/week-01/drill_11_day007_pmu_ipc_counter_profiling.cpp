// ==============================================================================
// 🥋 Drill 11 (Week 01 / Day 007): CS:APP §5.14 & Gregg Ch 6 — PMU Hardware Counters & IPC
//
// 📖 READING SOURCES:
// - Brendan Gregg: Systems Performance (Ch 6: CPU Profiling & Hardware PMU Events)
// - Bryant & O'Hallaron: Computer Systems (CS:APP 3rd Ed, §5.14: Profiling with PMU)
//
// 🎯 CORE LESSON:
// 1. Performance Monitoring Unit (PMU) Counters:
//    - `instructions` and `cycles` -> Instructions Per Cycle (IPC = instructions / cycles).
//    - High IPC (> 2.0) indicates compute saturation; low IPC (< 1.0) indicates memory stalls.
// 2. Cache Miss Rate = `L1_dcache_misses / L1_dcache_accesses`.
// 3. Branch Miss Rate = `branch_misses / total_branches`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_11_day007_pmu_ipc_counter_profiling.cpp -o drill11 && ./drill11
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cassert>
#include <cmath>

struct PMUMetrics {
    uint64_t cycles{0};
    uint64_t instructions{0};
    uint64_t branches{0};
    uint64_t branch_misses{0};
    uint64_t l1_accesses{0};
    uint64_t l1_misses{0};

    // TODO 1: Compute Instructions Per Cycle (IPC)
    double calculate_ipc() const {
        if (cycles == 0) return 0.0;
        return static_cast<double>(instructions) / static_cast<double>(cycles);
    }

    // TODO 2: Compute branch misprediction rate (%)
    double branch_mispredict_rate_pct() const {
        if (branches == 0) return 0.0;
        return (static_cast<double>(branch_misses) / static_cast<double>(branches)) * 100.0;
    }

    // TODO 3: Compute L1 cache miss rate (%)
    double l1_miss_rate_pct() const {
        if (l1_accesses == 0) return 0.0;
        return (static_cast<double>(l1_misses) / static_cast<double>(l1_accesses)) * 100.0;
    }
};

int main() {
    std::cout << "--- Week 01 Drill 11: PMU Hardware Event Counters & IPC ---\n\n";

    PMUMetrics sample{
        .cycles = 1000000,
        .instructions = 2500000,
        .branches = 500000,
        .branch_misses = 2500,
        .l1_accesses = 800000,
        .l1_misses = 16000
    };

    double ipc = sample.calculate_ipc();
    double branch_rate = sample.branch_mispredict_rate_pct();
    double l1_rate = sample.l1_miss_rate_pct();

    std::cout << "Measured IPC:                 " << ipc << " (Expected: 2.50)\n";
    std::cout << "Branch Misprediction Rate:    " << branch_rate << "% (Expected: 0.50%)\n";
    std::cout << "L1-D Cache Miss Rate:         " << l1_rate << "% (Expected: 2.00%)\n";

    assert(std::abs(ipc - 2.5) < 1e-5);
    assert(std::abs(branch_rate - 0.5) < 1e-5);
    assert(std::abs(l1_rate - 2.0) < 1e-5);

    std::cout << "\n✓ Week 01 Drill 11 Passed Successfully!\n";
    return 0;
}
