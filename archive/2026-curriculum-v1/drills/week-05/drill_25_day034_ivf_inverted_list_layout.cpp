// ==============================================================================
// 🥋 Drill 25 (Day 34.16): IVF Deep Dive (Part 2) — 64-Byte Cache-Aligned Inverted Lists
//
// 📖 READING SOURCES:
// - Drepper: What Every Programmer Should Know About Memory (§3.3 & §6.2)
// - Agner Fog: Optimizing Software in C++ (Ch 8: Memory Layout & Alignment)
//
// 🎯 CORE LESSON:
// 1. Inverted File (IVF) Memory Layout: A collection of $K$ distinct inverted posting lists.
// 2. Cache Line Alignment (`alignas(64)`): Contiguous vector storage inside each cluster must begin on a 64-byte boundary.
// 3. Vector Ingestion / Append: Adding $(id, \mathbf{v})$ to cluster $c$ without reallocating every vector.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_25_day034_ivf_inverted_list_layout.cpp -o drill25 && ./drill25
// ==============================================================================

#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>
#include <cstring>
#include <span>

struct alignas(64) InvertedList {
    std::vector<int32_t> ids;
    std::vector<float> data; // Contiguous flat array: N_c * dim floats

    // TODO 1: Implement vector append into inverted list
    // 1. Push id into ids
    // 2. Append dim floats from vec into data
    void append(int32_t id, const float* vec, size_t dim) {
        // [YOUR CODE HERE]
        (void)id;
        (void)vec;
        (void)dim;
    }

    [[nodiscard]] size_t size() const noexcept { return ids.size(); }

    [[nodiscard]] const float* get_vector(size_t index, size_t dim) const noexcept {
        return data.data() + index * dim;
    }
};

class IvfStorageLayout {
public:
    IvfStorageLayout(size_t num_lists, size_t dim)
        : nlist_(num_lists), dim_(dim), lists_(num_lists) {}

    void add_vector(size_t cluster_id, int32_t id, const float* vec) {
        assert(cluster_id < nlist_);
        lists_[cluster_id].append(id, vec, dim_);
    }

    [[nodiscard]] const InvertedList& get_list(size_t cluster_id) const noexcept {
        return lists_[cluster_id];
    }

    [[nodiscard]] size_t total_vectors() const noexcept {
        size_t total = 0;
        for (const auto& l : lists_) total += l.size();
        return total;
    }

private:
    size_t nlist_{0};
    size_t dim_{0};
    std::vector<InvertedList> lists_;
};

int main() {
    std::cout << "--- Drill 25: IVF Deep Dive Part 2 — 64-Byte Aligned Inverted Lists ---\n\n";

    constexpr size_t NLIST = 4;
    constexpr size_t DIM = 4;

    IvfStorageLayout ivf(NLIST, DIM);

    // Ingest 4 vectors across clusters
    float v0[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    float v1[4] = {5.0f, 6.0f, 7.0f, 8.0f};

    ivf.add_vector(0, 1001, v0);
    ivf.add_vector(0, 1002, v1);
    ivf.add_vector(3, 2001, v0);

    const auto& list0 = ivf.get_list(0);
    assert(list0.size() == 2);
    assert(list0.ids[0] == 1001);
    assert(list0.ids[1] == 1002);

    const float* stored_v1 = list0.get_vector(1, DIM);
    for (size_t d = 0; d < DIM; ++d) {
        assert(stored_v1[d] == v1[d]);
    }

    std::cout << "Cluster 0 has " << list0.size() << " vectors.\n";
    std::cout << "Total vectors in IVF layout: " << ivf.total_vectors() << "\n";
    assert(ivf.total_vectors() == 3);

    std::cout << "\n✓ Drill 25 Passed: IVF Inverted List storage layout operational!\n";
    return 0;
}
