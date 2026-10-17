// ==============================================================================
// 🥋 Drill 04 (Week 04 / Day 026): `secan` IVF — Multi-Probe Routing via `std::partial_sort`
//
// 📖 READING SOURCES:
// - `secan/src/index/ivf_flat.cpp`
//
// 🎯 CORE LESSON:
// 1. Inverted File (IVF) Multi-Probe:
//    At query time, find the top `nprobe` nearest coarse centroids (out of K clusters)
//    and scan only the inverted posting lists corresponding to those clusters.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_04_day026_multiprobe_ivf_routing.cpp -o drill04 && ./drill04
// ==============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cassert>

struct CentroidDistance {
    uint32_t cluster_id{0};
    float distance{0.0f};

    bool operator<(const CentroidDistance& other) const {
        return distance < other.distance;
    }
};

std::vector<uint32_t> select_top_nprobe_clusters(
    std::vector<CentroidDistance>& distances,
    size_t nprobe
) {
    std::partial_sort(
        distances.begin(),
        distances.begin() + static_cast<std::ptrdiff_t>(nprobe),
        distances.end()
    );

    std::vector<uint32_t> selected;
    selected.reserve(nprobe);
    for (size_t i = 0; i < nprobe; ++i) {
        selected.push_back(distances[i].cluster_id);
    }
    return selected;
}

int main() {
    std::cout << "--- Week 04 Drill 04: IVF Multi-Probe Cluster Routing ---\n\n";

    std::vector<CentroidDistance> clusters = {
        {0, 10.5f}, {1, 2.1f}, {2, 8.4f}, {3, 1.4f}, {4, 6.7f}
    };

    auto nprobe_ids = select_top_nprobe_clusters(clusters, 2);
    std::cout << "Selected nprobe=2 cluster IDs: [" << nprobe_ids[0] << ", " << nprobe_ids[1] << "]\n";

    assert(nprobe_ids.size() == 2);
    assert(nprobe_ids[0] == 3 && "Cluster 3 has min distance 1.4");
    assert(nprobe_ids[1] == 1 && "Cluster 1 has second min distance 2.1");

    std::cout << "\n✓ Week 04 Drill 04 Passed Successfully!\n";
    return 0;
}
