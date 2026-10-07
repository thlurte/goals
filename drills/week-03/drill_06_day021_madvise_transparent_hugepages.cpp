// ==============================================================================
// 🥋 Drill 06 (Week 03 / Day 021): Linux Systems — Transparent Hugepages (`madvise`)
//
// 📖 READING SOURCES:
// - Brendan Gregg: Systems Performance (Ch 7: Memory & TLB Misses)
//
// 🎯 CORE LESSON:
// 1. Translation Lookaside Buffer (TLB):
//    Standard Linux page size is 4KB. A 1GB vector database spans 262,144 pages, thrashing TLB.
// 2. Hugepages (2MB / 1GB):
//    `madvise(addr, length, MADV_HUGEPAGE)` hints to the Linux kernel to back the buffer
//    with 2MB hugepages, reducing TLB entries by 512x!
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_06_day021_madvise_transparent_hugepages.cpp -o drill06 && ./drill06
// ==============================================================================

#include <iostream>
#include <sys/mman.h>
#include <unistd.h>
#include <cassert>

int main() {
    std::cout << "--- Week 03 Drill 06: Linux Transparent Hugepages (MADV_HUGEPAGE) ---\n\n";

    size_t size = 2 * 1024 * 1024; // 2MB page size
    void* buffer = mmap(
        nullptr, size,
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1, 0
    );

    assert(buffer != MAP_FAILED);

    #if defined(MADV_HUGEPAGE)
    int ret = madvise(buffer, size, MADV_HUGEPAGE);
    std::cout << "madvise(MADV_HUGEPAGE) returned: " << ret << " (0 = Success)\n";
    assert(ret == 0);
    #endif

    munmap(buffer, size);
    std::cout << "\n✓ Week 03 Drill 06 Passed Successfully!\n";
    return 0;
}
