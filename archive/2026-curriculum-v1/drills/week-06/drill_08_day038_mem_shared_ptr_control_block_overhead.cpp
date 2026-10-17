// ==============================================================================
// 🥋 Drill: std::shared_ptr Control Block & std::make_shared Single Allocation
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 19: Use std::shared_ptr for shared-ownership resource management)
// - Meyers: Effective Modern C++ (Item 21: Prefer std::make_unique and std::make_shared to direct use of new)
//
// 🎯 CORE LESSON:
// 1. `std::shared_ptr` manages resources via a dynamically allocated control block containing ref counts.
// 2. `std::make_shared` performs 1 allocation (control block + managed object contiguous in memory).
// 3. `std::shared_ptr<T>(new T)` performs 2 separate allocations, increasing cache misses and memory fragmentation.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_08_day038_mem_shared_ptr_control_block_overhead.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <cassert>

struct Node {
    int val;
    explicit Node(int v) : val(v) {}
};

int main() {
    std::cout << "--- Drill 08: std::shared_ptr Control Block Overhead ---\n\n";

    // Prefer std::make_shared: single allocation
    std::shared_ptr<Node> p1 = std::make_shared<Node>(42);
    assert(p1.use_count() == 1);

    {
        std::shared_ptr<Node> p2 = p1;
        assert(p1.use_count() == 2);
        assert(p2.use_count() == 2);
        assert(p2->val == 42);
    } // p2 destroyed, refcount decremented

    assert(p1.use_count() == 1);
    std::cout << "Refcount accurately tracked across nested scopes.\n";

    std::cout << "\n✓ Drill 08 Passed: Control block refcounting verified!\n";
    return 0;
}
