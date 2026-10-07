// ==============================================================================
// 🥋 Drill 11 (Day 35.1): `secan` — Two-Stage Re-ranking Filter (std::partial_sort)
//
// 📖 READING SOURCES:
// - `secan` Two-Stage Retrieval Architecture
//
// 🎯 CORE LESSON:
// 1. O(N log K) partial sorting avoids full O(N log N) sorting overhead.
// 2. Struct with `bool operator<(const Candidate& other)` for custom ascending min-heaps.
// 3. Coarse filter over SQ8 -> Top-M candidates -> Fine FP32 re-ranking -> Top-K IDs.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_11_day035_twostage_rerank.cpp -o drill11 && ./drill11
// ==============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cassert>

struct Candidate {
    uint32_t id{0};
    float distance{0.0f};

    // TODO 1: Implement operator< for ascending distance comparison
    bool operator<(const Candidate& other) const {
        // [YOUR CODE HERE]
        return false;
    }
};

// TODO 2: Implement two-stage rerank using std::partial_sort
// 1. Partial sort candidates up to coarse_top_m
// 2. Extract first final_top_k IDs into output vector
std::vector<uint32_t> twostage_rerank(
    std::vector<Candidate>& coarse_candidates,
    size_t coarse_top_m,
    size_t final_top_k
) {
    // [YOUR CODE HERE]
    return {};
}

int main() {
    std::cout << "--- Drill 11: Two-Stage Re-ranking Filter ---\n\n";

    std::vector<Candidate> candidates = {
        {10, 5.2f}, {20, 1.1f}, {30, 8.4f}, {40, 2.3f}, {50, 0.4f}, {60, 3.9f}
    };

    auto top_k = twostage_rerank(candidates, 4, 2);
    std::cout << "Top-2 IDs: [" << top_k[0] << ", " << top_k[1] << "]\n";

    assert(top_k.size() == 2);
    assert(top_k[0] == 50 && "ID 50 has smallest distance (0.4)");
    assert(top_k[1] == 20 && "ID 20 has second smallest distance (1.1)");

    std::cout << "✓ Drill 11 Passed: Two-stage candidate filtering verified!\n";
    return 0;
}
