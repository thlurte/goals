// ==============================================================================
// 🥋 Drill 26 (Day 34.17): IVF Deep Dive (Part 3) — Multi-Probe Routing & Bounded Max-Heap
//
// 📖 READING SOURCES:
// - Jégou, Douze, Schmid: "Product Quantization for Nearest Neighbor Search" (IEEE TPAMI §4: IVF Routing)
// - Knuth: The Art of Computer Programming (Vol 3: Sorting and Searching)
//
// 🎯 CORE LESSON:
// 1. Multi-Probe Query Routing: Find the `nprobe` closest Voronoi centroids to query $q$.
// 2. Bounded Max-Heap Top-$K$ Filtering: Zero dynamic allocation top-$k$ min/max heap.
//    - Store $(distance, id)$ pairs.
//    - When heap size reaches $k$, only insert if new candidate distance $< \text{heap.top().distance}$.
//    - Pop the worst candidate and push the new one.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_26_day034_ivf_multiprobe_routing_heap.cpp -o drill26 && ./drill26
// ==============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cassert>

struct SearchResult {
    int32_t id{0};
    float distance{0.0f};

    // Max-heap comparator (worst element with largest distance on top)
    bool operator<(const SearchResult& other) const noexcept {
        return distance < other.distance;
    }
};

class BoundedTopKHeap {
public:
    explicit BoundedTopKHeap(size_t k) : k_(k) {}

    // TODO 1: Implement bounded top-k insertion
    // 1. If heap size < k_: push candidate directly
    // 2. Else if candidate.distance < heap_.top().distance:
    //    pop heap_.top(), then push candidate
    void push(int32_t id, float dist) {
        // [YOUR CODE HERE]
        (void)id;
        (void)dist;
    }

    // Returns results sorted from smallest distance to largest distance
    std::vector<SearchResult> extract_sorted() {
        std::vector<SearchResult> results;
        while (!heap_.empty()) {
            results.push_back(heap_.top());
            heap_.pop();
        }
        std::reverse(results.begin(), results.end());
        return results;
    }

    [[nodiscard]] size_t size() const noexcept { return heap_.size(); }

private:
    size_t k_{0};
    std::priority_queue<SearchResult> heap_;
};

// TODO 2: Implement centroid multi-probe routing
// Given query, centroids (k x dim), find the indices of the `nprobe` closest centroids
std::vector<size_t> route_multiprobe_centroids(
    const float* query,
    const float* centroids,
    size_t num_centroids,
    size_t dim,
    size_t nprobe
) {
    // [YOUR CODE HERE]
    (void)query;
    (void)centroids;
    (void)num_centroids;
    (void)dim;
    (void)nprobe;
    return {};
}

int main() {
    std::cout << "--- Drill 26: IVF Deep Dive Part 3 — Multi-Probe & Bounded Heap ---\n\n";

    // 1. Test Bounded Top-K Heap
    BoundedTopKHeap heap(3);
    heap.push(1, 10.5f);
    heap.push(2, 2.0f);
    heap.push(3, 15.0f);
    heap.push(4, 1.2f); // Should displace 15.0f
    heap.push(5, 5.0f); // Should displace 10.5f

    auto top3 = heap.extract_sorted();
    assert(top3.size() == 3);
    assert(top3[0].id == 4 && top3[0].distance == 1.2f);
    assert(top3[1].id == 2 && top3[1].distance == 2.0f);
    assert(top3[2].id == 5 && top3[2].distance == 5.0f);
    std::cout << "✓ Bounded Max-Heap Top-3 extraction verified!\n";

    // 2. Test Multi-Probe Routing
    constexpr size_t D = 2;
    constexpr size_t K = 4;
    float centroids[4 * 2] = {
        0.0f, 0.0f,   // C0 (dist ~ 0.0)
        1.0f, 1.0f,   // C1 (dist ~ 2.0)
        10.0f, 10.0f, // C2 (dist ~ 200)
        5.0f, 5.0f    // C3 (dist ~ 50)
    };

    float q[2] = {0.1f, 0.1f};
    auto probes = route_multiprobe_centroids(q, centroids, K, D, 2);

    assert(probes.size() == 2);
    assert(probes[0] == 0 && "Closest cluster must be C0");
    assert(probes[1] == 1 && "Second closest cluster must be C1");
    std::cout << "✓ Multi-probe routing (nprobe=2) verified!\n";

    std::cout << "\n✓ Drill 26 Passed: Multi-probe routing and bounded heap operational!\n";
    return 0;
}
