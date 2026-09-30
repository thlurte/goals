// ==============================================================================
// 🥋 Drill 26.2: Bounded Max-Heap for Top-K Nearest Neighbors
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -std=c++20 day026_drill_02_bounded_heap.cpp -o
// drill26_2 && ./drill26_2
//
// CONTEXT:
// When scanning an inverted posting list with N=50,000 vectors, you cannot
// allocate memory dynamically in the loop. You maintain a bounded max-heap of
// size K.
//
// C++ SYSTEMS LESSON:
// - Use std::priority_queue with a max-heap property: `heap.top()` holds the
//   *worst* (largest distance) candidate currently in the top-K.
// - If new_dist < heap.top(), we pop the worst and push the new candidate in
// O(log K).
// - Guarantees O(N log K) time and ZERO dynamic heap allocations.
// ==============================================================================

#include <cassert>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

struct SearchCandidate {
  float distance;
  int32_t id;

  // TODO 1: Implement operator< for max-heap
  // (In a max-heap, heap.top() must be the LARGEST distance among the top-k)
  bool operator<(const SearchCandidate &other) const noexcept {
    return distance < other.distance;
  }
};

int main() {
  std::cout << "--- Drill 26.2: Zero-Allocation Bounded Max-Heap Top-K ---\n\n";

  const size_t k = 5;
  std::priority_queue<SearchCandidate> heap;

  // Simulated streaming distances from an IVF inverted list
  std::vector<std::pair<int32_t, float>> stream = {
      {101, 8.4f}, {102, 3.2f}, {103, 12.0f}, {104, 1.1f},
      {105, 5.6f}, {106, 0.4f}, {107, 7.9f},  {108, 2.3f}};

  // TODO 2: Loop through the stream and maintain a bounded heap of size `k`
  // Logic:
  // 1. If heap.size() < k -> unconditionally add the candidate.
  // 2. Else if candidate dist < heap.top().distance -> pop the worst item,
  // then add candidate.
  // 3. Otherwise -> do nothing (ignore far vector).
  for (const auto &[id, dist] : stream) {
    if (heap.size() < k) {
      heap.push(SearchCandidate{dist, id});
    } else if (dist < heap.top().distance) {
      heap.pop();
      heap.push(SearchCandidate({dist, id}));
    }
  }

  // -------------------------------------------------------------------------
  // TODO 3: Extract the Top-K from the heap into a vector in ASCENDING order
  // (smallest first) Hint: heap.top() gives largest remaining element, so
  // fill the vector backwards!
  // -------------------------------------------------------------------------
  std::vector<SearchCandidate> top_k(heap.size());
  for (int i = heap.size() - 1; i >= 0; --i) {
    top_k[i] = heap.top();
    heap.pop();
  }

  // -------------------------------------------------------------------------
  // Output & Verification (Do not modify)
  // -------------------------------------------------------------------------
  std::cout << "Top " << k << " Nearest Neighbors in Ascending Order:\n";
  for (size_t i = 0; i < top_k.size(); ++i) {
    std::cout << "  Rank [" << i + 1 << "] ID: " << top_k[i].id
              << " | Distance: " << top_k[i].distance << "\n";
  }

  assert(top_k.size() == k);
  assert(top_k[0].id == 106 && top_k[0].distance == 0.4f);
  assert(top_k[1].id == 104 && top_k[1].distance == 1.1f);
  assert(top_k[4].id == 105 && top_k[4].distance == 5.6f);

  std::cout << "\n✓ Drill Passed: Bounded heap correctly extracted Top-K "
               "smallest distances.\n";
  return 0;
}
