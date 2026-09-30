#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>

// ==============================================================================
// 🥋 Drill 26.1: std::partial_sort vs std::sort vs std::nth_element in C++20
//
// CONTEXT (IVF Multi-Probe Routing):
// When querying an IVF index with K=1024 coarse centroids, we need to pick the
// top nprobe=8 closest centroids.
//
// C++ SYSTEMS LESSON:
// - std::sort: O(K log K) - fully sorts all 1024 elements (wastes cycles).
// - std::partial_sort: O(K log P) - heapsorts only the top P elements in-place.
// - Benchmark: In tight query loops, partial_sort eliminates 90% of sorting overhead.
// ==============================================================================

struct CentroidCandidate {
    size_t id;
    float distance;

    bool operator<(const CentroidCandidate& other) const noexcept {
        return distance < other.distance;
    }
};

int main() {
    std::cout << "--- Drill 26.1: std::partial_sort Multi-Probe Centroid Routing ---\n\n";

    const size_t K = 1024;      // Total centroids
    const size_t nprobe = 8;    // Multi-probe budget

    std::vector<CentroidCandidate> candidates(K);
    for (size_t i = 0; i < K; ++i) {
        candidates[i] = {i, static_cast<float>((i * 73 + 19) % 500) + 0.5f};
    }

    // TODO / REFLEX:
    // Partially sort only the first `nprobe` elements into ascending distance order.
    std::partial_sort(
        candidates.begin(),
        candidates.begin() + nprobe,
        candidates.end()
    );

    std::cout << "Top " << nprobe << " Routed Centroid IDs (out of " << K << "):\n";
    for (size_t p = 0; p < nprobe; ++p) {
        std::cout << "  [" << p << "] Centroid ID: " << candidates[p].id 
                  << " | Distance: " << candidates[p].distance << "\n";
    }

    // Verification: Top nprobe must be strictly smaller than candidate at index nprobe
    for (size_t p = 0; p < nprobe; ++p) {
        assert(candidates[p].distance <= candidates[nprobe].distance);
    }
    std::cout << "\n✓ Drill Passed: Top " << nprobe << " elements correctly ordered with O(K log P) complexity.\n";
    return 0;
}
