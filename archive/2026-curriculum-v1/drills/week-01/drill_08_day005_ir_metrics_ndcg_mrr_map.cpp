// ==============================================================================
// 🥋 Drill 08 (Week 01 / Day 005): Information Retrieval Ranking Metrics (NDCG, MRR, Recall)
//
// 📖 READING SOURCES:
// - Manning, Raghavan, Schütze: Introduction to Information Retrieval (Ch 8: Evaluation in IR)
// - `secan/tests/test_ir_metrics.cpp`
//
// 🎯 CORE LESSON:
// 1. Recall@K:
//    Fraction of relevant ground-truth neighbors found in the top-K retrieved candidates.
// 2. Mean Reciprocal Rank (MRR):
//    MRR = 1 / rank_{first_hit}
// 3. Discounted Cumulative Gain (DCG@K):
//    DCG@K = sum_{i=1}^K (rel_i / log2(i + 1))
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_08_day005_ir_metrics_ndcg_mrr_map.cpp -o drill08 && ./drill08
// ==============================================================================

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <cassert>

// TODO 1: Compute Recall@K
// retrieved: list of retrieved IDs in ranked order
// ground_truth: set of relevant ground-truth IDs
double compute_recall_at_k(
    const std::vector<uint32_t>& retrieved,
    const std::unordered_set<uint32_t>& ground_truth,
    size_t k
) {
    // [YOUR CODE HERE]
    return 0.0;
}

// TODO 2: Compute Reciprocal Rank (RR)
// 1.0 / rank (1-indexed) of the first matching ground-truth element; 0.0 if not found
double compute_mrr(
    const std::vector<uint32_t>& retrieved,
    const std::unordered_set<uint32_t>& ground_truth
) {
    // [YOUR CODE HERE]
    return 0.0;
}

int main() {
    std::cout << "--- Week 01 Drill 08: IR Evaluation Metrics (Recall & MRR) ---\n\n";

    std::vector<uint32_t> retrieved = {101, 102, 103, 104, 105};
    std::unordered_set<uint32_t> ground_truth = {103, 105, 107, 109};

    // Ground truth has 4 items. Retrieved has {103, 105} in top-5 -> Recall@5 = 2 / 4 = 0.50
    double recall5 = compute_recall_at_k(retrieved, ground_truth, 5);
    std::cout << "Recall@5: " << recall5 << " (Expected: 0.50)\n";
    assert(std::abs(recall5 - 0.50) < 1e-5);

    // First relevant item is 103 at rank 3 (1-indexed) -> RR = 1 / 3 = 0.33333...
    double mrr = compute_mrr(retrieved, ground_truth);
    std::cout << "MRR:      " << mrr << " (Expected: ~0.3333)\n";
    assert(std::abs(mrr - (1.0 / 3.0)) < 1e-4);

    std::cout << "\n✓ Week 01 Drill 08 Passed Successfully!\n";
    return 0;
}
