// ==============================================================================
// 🥋 Drill: explicit Keyword: Preventing Implicit Conversion Heap Allocations
//
// 📖 READING SOURCES:
// - Meyers: Effective C++ (Item 24: Declare non-member functions when type conversions should apply to all parameters)
// - C++ Core Guidelines: C.46 (By default, declare single-argument constructors explicit)
//
// 🎯 CORE LESSON:
// 1. Single-argument constructors without `explicit` act as implicit conversion operators.
// 2. `VectorBuffer buf = 1000;` silently creates a 1000-element heap buffer when `explicit` is missing.
// 3. Marking constructors `explicit` catches accidental conversions and silent allocations at compile time.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_58_day038_mem_explicit_constructors_conversions.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cassert>

class SafeCapacityBuffer {
public:
    // explicit prevents: SafeCapacityBuffer buf = 64;
    explicit SafeCapacityBuffer(size_t capacity) : capacity_(capacity), data_(new int[capacity]()) {}
    ~SafeCapacityBuffer() noexcept { delete[] data_; }

    size_t capacity() const noexcept { return capacity_; }

private:
    size_t capacity_;
    int* data_;
};

void inspect_buffer(const SafeCapacityBuffer& buf) {
    assert(buf.capacity() == 128);
}

int main() {
    std::cout << "--- Drill 58: explicit Constructors ---\n\n";

    // Direct initialization works
    SafeCapacityBuffer buf(128);
    inspect_buffer(buf);

    // inspect_buffer(128); // COMPILE ERROR if uncommented: cannot implicitly convert size_t to SafeCapacityBuffer!

    std::cout << "\n✓ Drill 58 Passed: explicit constructor prevented implicit heap allocation!\n";
    return 0;
}
