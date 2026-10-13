// ==============================================================================
// 🥋 Drill: std::unique_ptr Custom Deleter for POSIX mmap / munmap
//
// 📖 READING SOURCES:
// - POSIX Programmer's Manual: munmap(2)
// - Meyers: Effective Modern C++ (Item 18: Custom deleters)
//
// 🎯 CORE LESSON:
// 1. `munmap` requires both the mapped pointer address and the mapped byte length.
// 2. A stateful deleter struct storing `length` binds the unmap size to the `std::unique_ptr`.
// 3. Guarantees that virtual address space mappings are released upon scope exit.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_56_day038_mem_unique_ptr_mmap_deleter.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <sys/mman.h>
#include <cstdint>
#include <cassert>

struct MMapDeleter {
    size_t length;
    explicit MMapDeleter(size_t len = 0) : length(len) {}

    void operator()(void* addr) const noexcept {
        if (addr && addr != MAP_FAILED) {
            std::cout << "[MMapDeleter] Munmapping " << length << " bytes at " << addr << "\n";
            munmap(addr, length);
        }
    }
};

using UniqueMMap = std::unique_ptr<void, MMapDeleter>;

UniqueMMap allocate_anonymous_page(size_t length) {
    void* ptr = mmap(nullptr, length, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) return UniqueMMap(nullptr, MMapDeleter(0));
    return UniqueMMap(ptr, MMapDeleter(length));
}

int main() {
    std::cout << "--- Drill 56: std::unique_ptr for mmap / munmap ---\n\n";

    constexpr size_t PageSize = 4096;
    {
        UniqueMMap mapped = allocate_anonymous_page(PageSize);
        assert(mapped != nullptr);

        int* int_buf = static_cast<int*>(mapped.get());
        int_buf[0] = 777;
        assert(int_buf[0] == 777);
    } // Automatically unmapped via munmap!

    std::cout << "\n✓ Drill 56 Passed: RAII mmap/munmap unique_ptr fully operational!\n";
    return 0;
}
