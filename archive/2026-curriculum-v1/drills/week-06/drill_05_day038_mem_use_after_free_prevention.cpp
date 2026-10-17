// ==============================================================================
// 🥋 Drill: Preventing Use-After-Free & Dangling Pointer Hazards
//
// 📖 READING SOURCES:
// - C++ Core Guidelines: Lifetime Safety Profile
// - Meyers: Effective Modern C++ (Item 1: Understand template type deduction & reference lifetimes)
//
// 🎯 CORE LESSON:
// 1. Dangling pointers occur when referencing memory after it has been deallocated.
// 2. Never return references or pointers to local stack variables.
// 3. Non-owning observers (raw pointers / string_view / span) must never outlive the owning container.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_05_day038_mem_use_after_free_prevention.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <cassert>

// Anti-pattern: Returning reference to local temporary (UB)
// Pattern: Safe observer with bounded lifetime
class VectorStore {
public:
    void add(std::string name) {
        names_.push_back(std::move(name));
    }

    // Observer: Safe string_view valid as long as VectorStore isn't mutated
    std::string_view get_name_view(size_t index) const {
        assert(index < names_.size());
        return names_[index];
    }

    size_t size() const noexcept { return names_.size(); }

private:
    std::vector<std::string> names_;
};

int main() {
    std::cout << "--- Drill 05: Use-After-Free Prevention ---\n\n";

    VectorStore store;
    store.add("hnsw_index_l2");
    store.add("ivf_pq_cosine");

    std::string_view v0 = store.get_name_view(0);
    std::string_view v1 = store.get_name_view(1);

    assert(v0 == "hnsw_index_l2");
    assert(v1 == "ivf_pq_cosine");
    assert(store.size() == 2);

    std::cout << "Views successfully observed: " << v0 << ", " << v1 << "\n";
    std::cout << "\n✓ Drill 05 Passed: Lifetime boundaries respected without use-after-free!\n";
    return 0;
}
