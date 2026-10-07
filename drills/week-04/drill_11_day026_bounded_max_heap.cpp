// ==============================================================================
// 🥋 Drill 11 (Week 04 / Day 026): `secan` — Zero-Allocation Bounded Max-Heap for Top-K
//
// 📖 READING SOURCES:
// - `secan/src/search/heap.h`
//
// 🎯 CORE LESSON:
// 1. Inverted Posting List Traversal:
//    When scanning N=50,000 vectors in an inverted list, zero dynamic heap allocations
//    can be permitted in the inner loop.
// 2. Bounded Max-Heap Invariant:
//    - Use std::priority_queue with size K.
//    - `heap.top()` holds the largest (worst) distance currently in the top-K.
//    - If `new_dist < heap.top().distance`, pop the worst candidate and push the new one in O(log K).
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_11_day026_bounded_max_heap.cpp -o drill11 && ./drill11
// ==============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
#include <cassert>

struct SearchCandidate {
    float distance{0.0f};
    int32_t id{0};

    // Max-heap comparator (heap.top() is the LARGEST distance among Top-K)
    bool operator<(const SearchCandidate& other) const noexcept {
        return distance < other.distance;
    }
};

int main() {
    std::cout << "--- Week 04 Drill 11: Zero-Allocation Bounded Max-Heap Top-K ---\n\n";

    const size_t k = 5;
    std::priority_queue<SearchCandidate> heap;

    std::vector<std::pair<int32_t, float>> stream = {
        {101, 8.4f}, {102, 3.2f}, {103, 12.0f}, {104, 1.1f},
        {105, 5.6f}, {106, 0.4f}, {107, 7.9f},  {108, 2.3f}
    };

    for (const auto& [id, dist] : stream) {
        if (heap.size() < k) {
            heap.push(SearchCandidate{dist, id});
        } else if (dist < heap.top().distance) {
            heap.pop();
            heap.push(SearchCandidate{dist, id});
        }
    }

    std::vector<SearchCandidate> top_k(heap.size());
    for (int i = static_cast<int>(heap.size()) - 1; i >= 0; --i) {
        top_k[i] = heap.top();
        heap.pop();
    }

    std::cout << "Top " << k << " Nearest Neighbors in Ascending Order:\n";
    for (size_t i = 0; i < top_k.size(); ++i) {
        std::cout << "  Rank [" << i + 1 << "] ID: " << top_k[i].id
                  << " | Distance: " << top_k[i].distance << "\n";
    }

    assert(top_k.size() == k);
    assert(top_k[0].id == 106 && top_k[0].distance == 0.4f);
    assert(top_k[1].id == 104 && top_k[1].distance == 1.1f);
    assert(top_k[4].id == 105 && top_k[4].distance == 5.6f);

    std::cout << "\n✓ Week 04 Drill 11 Passed: Bounded heap extracted Top-K successfully!\n";
    return 0;
}
