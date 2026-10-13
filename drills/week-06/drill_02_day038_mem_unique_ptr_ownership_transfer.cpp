// ==============================================================================
// 🥋 Drill: std::unique_ptr Exclusive Ownership & Transfer via std::move
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 18: Use std::unique_ptr for exclusive-ownership resource management)
// - Scott Meyers: Effective C++ (Item 13: Use objects to manage resources)
//
// 🎯 CORE LESSON:
// 1. `std::unique_ptr` enforces strict single ownership of dynamically allocated objects.
// 2. Ownership is transferred using move semantics (`std::move`); copying is prohibited at compile time.
// 3. `std::make_unique` ensures exception-safe allocation without naked `new` expressions.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_02_day038_mem_unique_ptr_ownership_transfer.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <cassert>

struct VectorDescriptor {
    int id;
    int dimension;
    VectorDescriptor(int i, int d) : id(i), dimension(d) {}
};

std::unique_ptr<VectorDescriptor> create_descriptor(int id, int dim) {
    return std::make_unique<VectorDescriptor>(id, dim);
}

void consume_descriptor(std::unique_ptr<VectorDescriptor> desc) {
    assert(desc != nullptr);
    assert(desc->id == 101);
    // desc destroyed at end of function
}

int main() {
    std::cout << "--- Drill 02: std::unique_ptr Ownership Transfer ---\n\n";

    auto desc = create_descriptor(101, 128);
    assert(desc != nullptr);
    assert(desc->dimension == 128);

    // Transfer ownership
    consume_descriptor(std::move(desc));

    // After move, the source unique_ptr is guaranteed to be nullptr
    assert(desc == nullptr && "Moved-from unique_ptr must be null!");

    std::cout << "\n✓ Drill 02 Passed: std::unique_ptr ownership transfer verified!\n";
    return 0;
}
