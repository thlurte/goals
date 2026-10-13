// ==============================================================================
// 🥋 Drill: Zero-Copy Memory Mapping (mmap) & 4096-Byte Page Alignment
//
// 📖 READING SOURCES:
// - POSIX Programmer's Manual: mmap(2), sysconf(3)
// - Love: Linux System Programming (Ch 4: Advanced File I/O)
//
// 🎯 CORE LESSON:
// 1. `mmap` creates zero-copy virtual memory mappings page-aligned to 4096 bytes.
// 2. File offsets passed to `mmap` must be exact multiples of `sysconf(_SC_PAGESIZE)`.
// 3. `munmap` cleans up the virtual address space mapping upon destruction.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_32_day038_align_mmap_page_aligned_io.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <sys/mman.h>
#include <unistd.h>
#include <cstdint>
#include <cassert>

int main() {
    std::cout << "--- Drill 32: POSIX mmap Page Alignment ---\n\n";

    long page_size = sysconf(_SC_PAGE_SIZE);
    assert(page_size == 4096 && "Standard Linux page size is 4KB!");

    // Anonymous mapping (no file descriptor)
    void* addr = mmap(nullptr, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    assert(addr != MAP_FAILED);

    uintptr_t uaddr = reinterpret_cast<uintptr_t>(addr);
    assert(uaddr % 4096 == 0 && "mmap must return page-aligned address!");

    // Safely unmap
    int ret = munmap(addr, 4096);
    assert(ret == 0);

    std::cout << "mmap returned verified 4096-byte page aligned address: 0x" << std::hex << uaddr << std::dec << "\n";
    std::cout << "\n✓ Drill 32 Passed: mmap page-aligned virtual memory verified!\n";
    return 0;
}
