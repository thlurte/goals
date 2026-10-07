// ==============================================================================
// 🥋 Drill 06 (Week 04 / Day 027): `secan` IVF — Inverted List Skew & Cluster Splitting
//
// 📖 READING SOURCES:
// - `secan/src/index/ivf_flat.cpp`
//
// 🎯 CORE LESSON:
// 1. Inverted List Skew:
//    In high-dimensional spaces, non-uniform data creates "giant clusters" that take 10x longer to scan,
//    degrading p99 tail search latency.
// 2. Cluster Splitting:
//    Clusters with sizes exceeding `2 * median_size` are split into 2 sub-clusters.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_06_day027_ivf_list_skew_rebalancer.cpp -o drill06 && ./drill06
// ==============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

// Identify clusters exceeding 2x median list size
std::vector<size_t> find_oversized_clusters(const std::vector<size_t>& list_sizes) {
    if (list_sizes.empty()) return {};

    std::vector<size_t> sorted = list_sizes;
    std::sort(sorted.begin(), sorted.end());
    size_t median = sorted[sorted.size() / 2];
    size_t threshold = 2 * median;

    std::vector<size_t> oversized_indices;
    for (size_t i = 0; i < list_sizes.size(); ++i) {
        if (list_sizes[i] > threshold) {
            oversized_indices.push_back(i);
        }
    }
    return oversized_indices;
}

int main() {
    std::cout << "--- Week 04 Drill 06: IVF Inverted List Skew Detection ---\n\n";

    std::vector<size_t> list_sizes = {100, 120, 110, 500, 95, 105}; // Median = 105, 2x = 210
    auto oversized = find_oversized_clusters(list_sizes);

    std::cout << "Oversized cluster index: " << oversized[0] << " (Size: " << list_sizes[oversized[0]] << ")\n";

    assert(oversized.size() == 1);
    assert(oversized[0] == 3 && "Cluster 3 (size 500) must be flagged for splitting!");

    std::cout << "\n✓ Week 04 Drill 06 Passed Successfully!\n";
    return 0;
}
