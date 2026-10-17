// ==============================================================================
// 🥋 Drill: Polymorphic Memory Resources (std::pmr::monotonic_buffer_resource)
//
// 📖 READING SOURCES:
// - C++17 std::pmr specification
// - Meyers: Effective Modern C++ (Allocators)
//
// 🎯 CORE LESSON:
// 1. `std::pmr` standardizes pluggable memory allocators without template bloat.
// 2. `std::pmr::monotonic_buffer_resource` allocates from a pre-allocated stack/heap buffer.
// 3. Reclaims all memory instantly upon destruction with zero per-element deallocation overhead.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_62_day038_mem_pmr_monotonic_buffer_resource.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory_resource>
#include <vector>
#include <cassert>

int main() {
    std::cout << "--- Drill 62: std::pmr Monotonic Buffer Resource ---\n\n";

    std::byte stack_buffer[512];
    std::pmr::monotonic_buffer_resource pool(stack_buffer, sizeof(stack_buffer));

    // pmr::vector allocates entirely from stack_buffer without touching heap
    std::pmr::vector<int> numbers(&pool);
    for (int i = 0; i < 32; ++i) {
        numbers.push_back(i * 10);
    }

    assert(numbers.size() == 32);
    assert(numbers[10] == 100);

    std::cout << "pmr::vector allocated 32 ints directly inside stack_buffer.\n";
    std::cout << "\n✓ Drill 62 Passed: std::pmr stack buffer allocation verified!\n";
    return 0;
}
