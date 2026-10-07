// ==============================================================================
// 🥋 Drill 02 (Week 01 / Day 002): Amdahl's Law & Distributed Latency
// Percentiles
//
// 📖 READING SOURCES:
// - Hennessy & Patterson: Computer Architecture (Ch 1: Amdahl's Law & Speedup)
// - Martin Kleppmann: Designing Data-Intensive Applications (DDIA Ch 1: Latency
// & SLAs)
//
// 🎯 CORE LESSON:
// 1. Amdahl's Law:
//    Speedup_Overall = 1 / ((1 - f) + (f / s))
//    where f = fraction of execution time enhanced, s = speedup of the enhanced
//    portion. If SIMD vectorizes 90% of vector search (f = 0.90) by 8x (s = 8),
//    max overall speedup = 4.7x!
// 2. Latency Percentiles (P50 / P95 / P99):
//    Calculated from sorted request durations: P_k index = ceil(k/100 * N) - 1.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra
// drill_02_day002_amdahls_law_latency_percentiles.cpp -o drill02 && ./drill02
// ==============================================================================

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

// TODO 1: Implement Amdahl's Law Speedup calculation
// fraction_enhanced (f) in [0.0, 1.0], speedup_enhanced (s) >= 1.0
// Return overall theoretical speedup
constexpr double amdahls_speedup(double fraction_enhanced,
                                 double speedup_enhanced) {

  return 1 / ((1 - fraction_enhanced) + (fraction_enhanced / speedup_enhanced));
}

// TODO 2: Compute exact p-th percentile latency (e.g. p = 99.0 for P99)
// 1. Sort the latencies vector ascending
// 2. Calculate index = ceil((p / 100.0) * N) - 1
// 3. Return latencies[index]
double calculate_percentile(std::vector<double> latencies, double p) {
  // [YOUR CODE HERE]
  if (latencies.empty())
    return 0.0;
  std::sort(latencies.begin(), latencies.end());

  size_t n = latencies.size();
  size_t idx =
      static_cast<size_t>(std::ceil((p / 100.0) * static_cast<double>(n))) - 1;
  return latencies[idx];
}

int main() {
  std::cout
      << "--- Week 01 Drill 02: Amdahl's Law & Latency Percentiles ---\n\n";

  // Test Part 1: Amdahl's Law
  // f = 0.90, s = 8.0 -> Speedup = 1 / (0.10 + 0.90 / 8) = 1 / (0.10 + 0.1125)
  // = 1 / 0.2125 = 4.70588x
  double s = amdahls_speedup(0.90, 8.0);
  std::cout << "Amdahl's Speedup (f=0.90, s=8.0): " << s
            << "x (Expected: ~4.7059x)\n";
  assert(std::abs(s - 4.70588) < 1e-4);

  // Test Part 2: Latency Percentiles
  // 100 latencies from 1.0ms to 100.0ms
  std::vector<double> latencies(100);
  for (size_t i = 0; i < 100; ++i)
    latencies[i] = static_cast<double>(i + 1);

  double p50 = calculate_percentile(latencies, 50.0);
  double p95 = calculate_percentile(latencies, 95.0);
  double p99 = calculate_percentile(latencies, 99.0);

  std::cout << "P50 Latency: " << p50 << " ms (Expected: 50.0)\n";
  std::cout << "P95 Latency: " << p95 << " ms (Expected: 95.0)\n";
  std::cout << "P99 Latency: " << p99 << " ms (Expected: 99.0)\n";

  assert(p50 == 50.0);
  assert(p95 == 95.0);
  assert(p99 == 99.0);

  std::cout << "\n✓ Week 01 Drill 02 Passed Successfully!\n";
  return 0;
}
