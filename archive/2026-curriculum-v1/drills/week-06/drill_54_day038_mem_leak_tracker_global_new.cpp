// ==============================================================================
// 🥋 Drill: Programmatic Memory Leak Detection via Overloaded operator new
//
// 📖 READING SOURCES:
// - Stroustrup: The C++ Programming Language (Ch 19: Special Operators: operator new/delete)
// - Meyers: More Effective C++ (Item 8: Understand the different meanings of new and delete)
//
// 🎯 CORE LESSON:
// 1. Overloading `operator new` and `operator delete` allows intercepting all heap allocations.
// 2. Tracking total allocated bytes minus freed bytes enables programmatic leak assertion.
// 3. Clean RAII designs guarantee net allocated bytes return to exactly zero on scope exit.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_54_day038_mem_leak_tracker_global_new.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <new>
#include <cassert>

static size_t s_active_heap_bytes = 0;

void* operator new(size_t size) {
    s_active_heap_bytes += size;
    void* ptr = std::malloc(size);
    if (!ptr) throw std::bad_alloc();
    return ptr;
}

void operator delete(void* ptr, size_t size) noexcept {
    s_active_heap_bytes -= size;
    std::free(ptr);
}

void operator delete(void* ptr) noexcept {
    std::free(ptr);
}

template <typename T>
class ScopedHeapItem {
public:
    ScopedHeapItem() : ptr_(new T()) {
        *ptr_ = 3.14;
        asm volatile("" : "+r"(ptr_) : : "memory");
    }
    ~ScopedHeapItem() noexcept { delete ptr_; }
private:
    T* ptr_;
};

int main() {
    std::cout << "--- Drill 54: Programmatic Memory Leak Tracker ---\n\n";

    size_t initial_bytes = s_active_heap_bytes;

    {
        ScopedHeapItem<double> item1;
        ScopedHeapItem<double> item2;
        assert(s_active_heap_bytes > initial_bytes);
        std::cout << "Active heap bytes during scope: " << s_active_heap_bytes << "\n";
    }

    assert(s_active_heap_bytes == initial_bytes && "Net heap allocations must balance to zero!");
    std::cout << "Active heap bytes after scope exit: " << s_active_heap_bytes << " (Zero leaks!)\n";

    std::cout << "\n✓ Drill 54 Passed: Programmatic leak detection confirmed zero leaks!\n";
    return 0;
}
