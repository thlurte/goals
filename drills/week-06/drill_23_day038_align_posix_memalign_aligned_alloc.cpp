// ==============================================================================
// 🥋 Drill: Dynamic Heap Alignment: posix_memalign & std::aligned_alloc
//
// 📖 READING SOURCES:
// - POSIX Programmer's Manual: posix_memalign(3)
// - C++ Reference: std::aligned_alloc
//
// 🎯 CORE LESSON:
// 1. Standard `malloc` only guarantees standard alignment (`alignof(std::max_align_t)`, typically 16 bytes).
// 2. `posix_memalign` allocates heap memory aligned to any power-of-two multiple of `sizeof(void*)`.
// 3. Memory allocated by `posix_memalign` is freed using standard `std::free()`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_23_day038_align_posix_memalign_aligned_alloc.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cassert>

int main() {
    std::cout << "--- Drill 23: posix_memalign Heap Allocation ---\n\n";

    constexpr size_t Alignment = 64;
    constexpr size_t SizeBytes = 1024;

    void* raw_ptr = nullptr;
    int ret = posix_memalign(&raw_ptr, Alignment, SizeBytes);
    assert(ret == 0 && raw_ptr != nullptr);

    uintptr_t addr = reinterpret_cast<uintptr_t>(raw_ptr);
    std::cout << "Allocated heap pointer at: 0x" << std::hex << addr << std::dec << "\n";
    assert(addr % Alignment == 0 && "Heap pointer must satisfy 64-byte alignment!");

    std::free(raw_ptr);
    std::cout << "\n✓ Drill 23 Passed: posix_memalign allocated verified 64-byte aligned memory!\n";
    return 0;
}
