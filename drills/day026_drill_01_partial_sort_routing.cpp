// ==============================================================================
// 🥋 Drill 26.1: std::partial_sort vs std::sort in C++20
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -std=c++20 day026_drill_01_partial_sort_routing.cpp -o
// drill26_1 && ./drill26_1
//
// CONTEXT (IVF Multi-Probe Routing):
// When querying an IVF index with K=1024 coarse centroids, we need to pick the
// top nprobe=8 closest centroids.
//
// C++ SYSTEMS LESSON:
// - std::sort: O(K log K) - fully sorts all 1024 elements (wastes cycles).
// - std::partial_sort: O(K log P) - heapsorts only the top P elements in-place.
// ==============================================================================

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

struct CentroidCandidate {
  size_t id;
  float distance;

  // TODO 1: Implement operator< to compare candidates by distance
  // (Smaller distance comes first in ascending sort)
  bool operator<(const CentroidCandidate &other) const noexcept {
    return distance < other.distance;
  }
};

int main() {
  std::cout << "--- Drill 26.1: std::partial_sort Multi-Probe Centroid Routing "
               "---\n\n";

  const size_t K = 1024;   // Total centroids
  const size_t nprobe = 8; // Multi-probe budget (top 8 closest)

  std::vector<CentroidCandidate> candidates(K);
  for (size_t i = 0; i < K; ++i) {
    candidates[i] = {i, static_cast<float>((i * 73 + 19) % 500) + 0.5f};
  }

  // TODO 2: Use std::partial_sort to sort ONLY the top `nprobe` elements
  // in-place Hint: std::partial_sort takes (beginning, middle, end) [YOUR CODE
  // HERE]
  std::partial_sort(candidates.begin(), candidates.begin() + nprobe,
                    candidates.end());
  // -------------------------------------------------------------------------
  // Output & Verification (Do not modify)
  // -------------------------------------------------------------------------
  std::cout << "Top " << nprobe << " Routed Centroid IDs (out of " << K
            << "):\n";
  for (size_t p = 0; p < nprobe; ++p) {
    std::cout << "  [" << p << "] Centroid ID: " << candidates[p].id
              << " | Distance: " << candidates[p].distance << "\n";
  }

  // Verification: Top nprobe must be strictly smaller than candidate at index
  // nprobe
  for (size_t p = 0; p < nprobe; ++p) {
    assert(candidates[p].distance <= candidates[nprobe].distance);
  }
  std::cout << "\n✓ Drill Passed: Top " << nprobe
            << " elements correctly ordered with O(K log P) complexity.\n";
  return 0;
}
