// ==============================================================================
// 🥋 Drill: Self-Assignment Hazard & Safe operator= Guards
//
// 📖 READING SOURCES:
// - Meyers: Effective C++ (Item 11: Handle assignment to self in operator=)
// - Sutter: Exceptional C++ (Item 11: Self-assignment)
//
// 🎯 CORE LESSON:
// 1. Naive assignment: `delete[] data_; data_ = new float[other.size_];` corrupts state if `this == &other`.
// 2. If `a = a` occurs, deleting `data_` deletes the exact source memory before copying it.
// 3. Always check `if (this != &other)` or use the Copy-and-Swap idiom.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_55_day038_mem_self_assignment_hazard.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <algorithm>
#include <cassert>

class VectorSeries {
public:
    explicit VectorSeries(size_t n, int val = 0) : size_(n), data_(new int[n]) {
        std::fill(data_, data_ + size_, val);
    }
    ~VectorSeries() noexcept { delete[] data_; }

    VectorSeries(const VectorSeries& other) : size_(other.size_), data_(new int[other.size_]) {
        std::copy(other.data_, other.data_ + size_, data_);
    }

    // Safe against self-assignment:
    VectorSeries& operator=(const VectorSeries& other) {
        if (this != &other) { // Guard prevents self-destruction!
            int* new_data = new int[other.size_];
            std::copy(other.data_, other.data_ + other.size_, new_data);
            delete[] data_;
            data_ = new_data;
            size_ = other.size_;
        }
        return *this;
    }

    int get(size_t i) const { return data_[i]; }

private:
    size_t size_;
    int* data_;
};

int main() {
    std::cout << "--- Drill 55: Self-Assignment Guard Verification ---\n\n";

    VectorSeries s(8, 42);
    assert(s.get(0) == 42);

    // Self-assignment
    s = s;
    assert(s.get(0) == 42 && "Self-assignment must preserve existing data without corruption!");

    std::cout << "\n✓ Drill 55 Passed: Self-assignment guard safely preserved object state!\n";
    return 0;
}
