// ==============================================================================
// 🥋 Drill: Placement new[] vs Scalar Placement: Reverse Destruction Order
//
// 📖 READING SOURCES:
// - Stroustrup: The C++ Programming Language (Ch 11.2: Memory Allocation)
// - Meyers: Effective C++ (Item 16: Use the same form in corresponding uses of new and delete)
//
// 🎯 CORE LESSON:
// 1. Constructing objects in-place with placement `new` requires manual destructor invocation.
// 2. C++ object destruction order must strictly reverse constructor order.
// 3. Array elements must be destroyed in reverse order: from `n - 1` down to `0`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_61_day038_mem_placement_new_array_destruction.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <new>
#include <vector>
#include <cassert>

static std::vector<int> s_destroyed_order;

struct Sensor {
    int id;
    explicit Sensor(int i) : id(i) {}
    ~Sensor() { s_destroyed_order.push_back(id); }
};

int main() {
    std::cout << "--- Drill 61: Placement new Array Reverse Destruction ---\n\n";

    constexpr size_t N = 4;
    alignas(Sensor) std::byte storage[N * sizeof(Sensor)];

    // Construct 0, 1, 2, 3
    Sensor* sensors = reinterpret_cast<Sensor*>(storage);
    for (size_t i = 0; i < N; ++i) {
        new (&sensors[i]) Sensor(static_cast<int>(i));
    }

    // Manual destruction in reverse order: 3, 2, 1, 0
    for (size_t i = N; i > 0; --i) {
        sensors[i - 1].~Sensor();
    }

    assert(s_destroyed_order.size() == 4);
    assert(s_destroyed_order[0] == 3);
    assert(s_destroyed_order[1] == 2);
    assert(s_destroyed_order[2] == 1);
    assert(s_destroyed_order[3] == 0);

    std::cout << "\n✓ Drill 61 Passed: Reverse destructor order verified!\n";
    return 0;
}
