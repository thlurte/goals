// ==============================================================================
// 🥋 Drill: Strong Exception Safety with the Copy-and-Swap Idiom
//
// 📖 READING SOURCES:
// - Meyers: Effective C++ (Item 11: Handle assignment to self in operator=)
// - Sutter: Exceptional C++ (Item 12: Assignment Operators)
//
// 🎯 CORE LESSON:
// 1. The copy-and-swap idiom implements `operator=` by taking the argument by value (invoking copy ctor).
// 2. It then calls `swap(*this, temp)` to exchange state.
// 3. Guarantees strong exception safety and automatically handles self-assignment.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_14_day038_mem_copy_and_swap_idiom.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <algorithm>
#include <utility>
#include <cassert>

class Buffer {
public:
    explicit Buffer(size_t n = 0) : size_(n), data_(n ? new int[n]() : nullptr) {}

    ~Buffer() noexcept { delete[] data_; }

    // Copy Constructor
    Buffer(const Buffer& other) : size_(other.size_), data_(other.size_ ? new int[other.size_] : nullptr) {
        if (data_) {
            std::copy(other.data_, other.data_ + size_, data_);
        }
    }

    // Move Constructor
    Buffer(Buffer&& other) noexcept : Buffer() {
        swap(*this, other);
    }

    friend void swap(Buffer& first, Buffer& second) noexcept {
        using std::swap;
        swap(first.size_, second.size_);
        swap(first.data_, second.data_);
    }

    // Copy-and-Swap: Pass-by-value handles both copy and move assignment!
    Buffer& operator=(Buffer other) noexcept {
        swap(*this, other);
        return *this;
    }

    size_t size() const noexcept { return size_; }
    int& operator[](size_t i) { return data_[i]; }

private:
    size_t size_;
    int* data_;
};

int main() {
    std::cout << "--- Drill 14: Copy-and-Swap Idiom ---\n\n";

    Buffer b1(5);
    b1[0] = 100;

    Buffer b2;
    b2 = b1; // Copy assign
    assert(b2.size() == 5);
    assert(b2[0] == 100);

    Buffer b3;
    b3 = std::move(b1); // Move assign
    assert(b3[0] == 100);

    std::cout << "\n✓ Drill 14 Passed: Copy-and-Swap idiom unified assignment!\n";
    return 0;
}
