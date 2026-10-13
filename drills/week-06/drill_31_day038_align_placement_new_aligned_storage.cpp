// ==============================================================================
// 🥋 Drill: Placement new into alignas(64) Raw Byte Storage
//
// 📖 READING SOURCES:
// - cppreference: Placement new
// - Meyers: Effective C++ (Item 52: Understand placement new)
//
// 🎯 CORE LESSON:
// 1. `alignas(64) std::byte storage[sizeof(T)]` guarantees stack buffer alignment for type `T`.
// 2. Placement `new (storage) T(...)` constructs an object in-place at the exact aligned address.
// 3. Destruction must be manually invoked with `ptr->~T()` before storage goes out of scope.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_31_day038_align_placement_new_aligned_storage.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstddef>
#include <cstdint>
#include <new>
#include <cassert>

static int s_desc_destructor_count = 0;

struct VectorDescriptor {
    int id;
    float norm;
    VectorDescriptor(int i, float n) : id(i), norm(n) {}
    ~VectorDescriptor() { s_desc_destructor_count++; }
};

int main() {
    std::cout << "--- Drill 31: Placement new in alignas(64) Storage ---\n\n";

    alignas(64) std::byte raw_storage[sizeof(VectorDescriptor)];
    assert(reinterpret_cast<uintptr_t>(raw_storage) % 64 == 0);

    // Construct in-place
    VectorDescriptor* desc = new (raw_storage) VectorDescriptor(42, 1.0f);
    assert(desc->id == 42);
    assert(desc->norm == 1.0f);

    // Explicit destructor
    desc->~VectorDescriptor();
    assert(s_desc_destructor_count == 1);

    std::cout << "\n✓ Drill 31 Passed: Placement new into aligned storage verified!\n";
    return 0;
}
