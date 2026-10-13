// ==============================================================================
// 🥋 Drill: std::shared_ptr Aliasing Constructor for Sub-Object Sharing
//
// 📖 READING SOURCES:
// - cppreference: std::shared_ptr::shared_ptr (aliasing constructor)
// - Meyers: Effective Modern C++ (Item 19: shared_ptr)
//
// 🎯 CORE LESSON:
// 1. The aliasing constructor `std::shared_ptr<T>(shared_ptr<Owner>, &owner->member)` shares ownership.
// 2. Points to a sub-object while managing the lifetime of the entire parent container.
// 3. Prevents the parent index from being destroyed while a query holds a pointer to its posting list.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_57_day038_mem_shared_ptr_aliasing_constructor.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <vector>
#include <cassert>

struct VectorIndexData {
    int index_id;
    std::vector<float> centroids;
    VectorIndexData(int id, size_t n) : index_id(id), centroids(n, 1.0f) {}
    ~VectorIndexData() { std::cout << "[VectorIndexData] Destroyed\n"; }
};

int main() {
    std::cout << "--- Drill 57: std::shared_ptr Aliasing Constructor ---\n\n";

    std::shared_ptr<float> centroid_ptr;

    {
        auto parent_index = std::make_shared<VectorIndexData>(99, 128);
        assert(parent_index.use_count() == 1);

        // Aliasing constructor: centroid_ptr points to &parent_index->centroids[0],
        // but shares the control block of parent_index!
        centroid_ptr = std::shared_ptr<float>(parent_index, &parent_index->centroids[0]);
        assert(parent_index.use_count() == 2);
    } // parent_index goes out of scope, but VectorIndexData is NOT destroyed!

    assert(centroid_ptr.use_count() == 1);
    assert(*centroid_ptr == 1.0f);
    std::cout << "Parent kept alive while centroid_ptr is active: val=" << *centroid_ptr << "\n";

    centroid_ptr.reset(); // VectorIndexData destroyed here
    std::cout << "\n✓ Drill 57 Passed: Aliasing constructor shared sub-object verified!\n";
    return 0;
}
