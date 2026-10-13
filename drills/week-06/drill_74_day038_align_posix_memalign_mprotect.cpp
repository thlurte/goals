// ==============================================================================
// 🥋 Drill: Page Alignment & Memory Protection: posix_memalign + mprotect
//
// 📖 READING SOURCES:
// - POSIX Programmer's Manual: mprotect(2)
// - Love: Linux System Programming (Ch 9: Memory Management)
//
// 🎯 CORE LESSON:
// 1. `mprotect` requires pointer addresses to be strict multiples of the OS page size (4096 bytes).
// 2. `posix_memalign(&ptr, 4096, size)` allocates page-aligned virtual memory.
// 3. `mprotect(ptr, size, PROT_READ)` makes a precomputed index read-only to prevent corruption.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_74_day038_align_posix_memalign_mprotect.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdlib>
#include <sys/mman.h>
#include <unistd.h>
#include <cstdint>
#include <cassert>

int main() {
    std::cout << "--- Drill 74: posix_memalign + mprotect ---\n\n";

    constexpr size_t PageSize = 4096;
    void* ptr = nullptr;
    int ret = posix_memalign(&ptr, PageSize, PageSize);
    assert(ret == 0 && ptr != nullptr);
    assert(reinterpret_cast<uintptr_t>(ptr) % PageSize == 0);

    // Populate data
    int* data = static_cast<int*>(ptr);
    data[0] = 42;

    // Set to Read-Only
    int prot_ret = mprotect(ptr, PageSize, PROT_READ);
    assert(prot_ret == 0);

    // Reading is permitted
    assert(data[0] == 42);

    // Restore Write permission before free()
    mprotect(ptr, PageSize, PROT_READ | PROT_WRITE);
    std::free(ptr);

    std::cout << "\n✓ Drill 74 Passed: Page-aligned mprotect permissions verified!\n";
    return 0;
}
