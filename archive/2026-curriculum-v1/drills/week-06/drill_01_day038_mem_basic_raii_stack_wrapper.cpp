// ==============================================================================
// 🥋 Drill: Basic RAII Stack-Managed Heap Resource (Rule of 0 / Rule of 3)
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 11: Prefer deleted functions to private undefined)
// - Stroustrup: The C++ Programming Language (Ch 13: Resource Management)
//
// 🎯 CORE LESSON:
// 1. RAII guarantees deterministic resource cleanup: constructor acquires, destructor releases.
// 2. Destructors are invoked automatically when objects go out of scope, even during exceptions.
// 3. Disabling copy operations (`= delete`) prevents double-free errors when raw pointers are managed.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_01_day038_mem_basic_raii_stack_wrapper.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cassert>
#include <utility>

class RawIntBuffer {
public:
    explicit RawIntBuffer(size_t size) : size_(size), data_(new int[size]()) {
        std::cout << "[RawIntBuffer] Allocated " << size_ << " ints\n";
    }

    ~RawIntBuffer() noexcept {
        delete[] data_;
        std::cout << "[RawIntBuffer] Destructed and freed\n";
    }

    // Non-copyable to prevent double-free
    RawIntBuffer(const RawIntBuffer&) = delete;
    RawIntBuffer& operator=(const RawIntBuffer&) = delete;

    size_t size() const noexcept { return size_; }
    int& operator[](size_t idx) { return data_[idx]; }
    const int& operator[](size_t idx) const { return data_[idx]; }
    int* data() noexcept { return data_; }

private:
    size_t size_;
    int* data_;
};

int main() {
    std::cout << "--- Drill 01: Basic RAII Stack-Managed Resource ---\n\n";

    {
        RawIntBuffer buf(16);
        assert(buf.size() == 16);
        buf[0] = 42;
        buf[15] = 100;
        assert(buf[0] == 42);
        assert(buf[15] == 100);
        std::cout << "Buffer successfully manipulated inside scope.\n";
    } // buf destructor automatically called here

    std::cout << "\n✓ Drill 01 Passed: RAII stack resource managed safely without leaks!\n";
    return 0;
}
