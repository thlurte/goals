// ==============================================================================
// 🥋 Drill 05 (Week 03 / Day 021): FLANN — Randomized KD-Tree Node Structure
//
// 📖 READING SOURCES:
// - Muja & Lowe: "Fast Approximate Nearest Neighbors with Automatic Algorithm Configuration"
//
// 🎯 CORE LESSON:
// 1. Randomized KD-Trees pick splitting dimensions among top highest-variance dimensions.
// 2. Binary partition: left child (< split_val), right child (>= split_val).
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_05_day021_randomized_kd_tree_search.cpp -o drill05 && ./drill05
// ==============================================================================

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

struct KDNode {
    int split_dim{-1};
    float split_val{0.0f};
    std::vector<uint32_t> point_indices;
    std::unique_ptr<KDNode> left;
    std::unique_ptr<KDNode> right;

    bool is_leaf() const { return left == nullptr && right == nullptr; }
};

int main() {
    std::cout << "--- Week 03 Drill 05: Randomized KD-Tree Structure ---\n\n";

    auto root = std::make_unique<KDNode>();
    root->split_dim = 0;
    root->split_val = 5.0f;

    root->left = std::make_unique<KDNode>();
    root->left->point_indices = {0, 1, 2};

    root->right = std::make_unique<KDNode>();
    root->right->point_indices = {3, 4};

    assert(!root->is_leaf());
    assert(root->left->is_leaf());
    assert(root->right->is_leaf());

    std::cout << "✓ KD-Tree node construction verified!\n";
    std::cout << "\n✓ Week 03 Drill 05 Passed Successfully!\n";
    return 0;
}
