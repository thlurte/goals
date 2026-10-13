// ==============================================================================
// 🥋 Drill: Empty Base Class Optimization (EBCO) in std::unique_ptr Deleters
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 18: Size of std::unique_ptr with custom deleters)
// - Vandevoorde & Josuttis: C++ Templates (Ch 21: Empty Base Class Optimization)
//
// 🎯 CORE LESSON:
// 1. A stateless functor deleter incurs 0 bytes overhead due to EBCO (`sizeof == sizeof(void*)`).
// 2. A function pointer deleter (`void(*)(T*)`) doubles the pointer size (`sizeof == 2 * sizeof(void*)`).
// 3. In performance-critical engines, prefer stateless struct deleters over function pointers.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_07_day038_mem_custom_deleter_empty_base_optimization.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <cstdlib>
#include <cassert>

struct FreeDeleter {
    void operator()(void* p) const noexcept {
        std::free(p);
    }
};

void c_free_func(void* p) {
    std::free(p);
}

int main() {
    std::cout << "--- Drill 07: Deleter EBCO Size Comparison ---\n\n";

    using DefaultPtr = std::unique_ptr<int>;
    using FunctorPtr = std::unique_ptr<int, FreeDeleter>;
    using FuncPtrPtr = std::unique_ptr<int, void(*)(void*)>;

    std::cout << "sizeof(DefaultPtr): " << sizeof(DefaultPtr) << " bytes\n";
    std::cout << "sizeof(FunctorPtr): " << sizeof(FunctorPtr) << " bytes\n";
    std::cout << "sizeof(FuncPtrPtr): " << sizeof(FuncPtrPtr) << " bytes\n";

    // Stateless functor has zero size overhead (8 bytes on 64-bit)
    assert(sizeof(DefaultPtr) == sizeof(void*));
    assert(sizeof(FunctorPtr) == sizeof(void*));
    // Function pointer deleter stores the function pointer (16 bytes on 64-bit)
    assert(sizeof(FuncPtrPtr) == 2 * sizeof(void*));

    std::cout << "\n✓ Drill 07 Passed: EBCO zero-cost deleter verified!\n";
    return 0;
}
