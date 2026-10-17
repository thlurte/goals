// ==============================================================================
// 🥋 Drill: Complete Rule of Five: Deep Copy vs Move Semantics
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 17: Special member function generation rules)
// - C++ Core Guidelines: C.21 (If you define or =delete any default operation, define or =delete them all)
//
// 🎯 CORE LESSON:
// 1. The Rule of Five: Destructor, Copy Ctor, Copy Assign, Move Ctor, Move Assign.
// 2. Copy operations must perform a deep copy of heap resources to prevent aliased pointers.
// 3. Move operations must transfer ownership and leave the donor in a valid empty state.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_13_day038_mem_rule_of_five_deep_copy_array.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <algorithm>
#include <utility>
#include <cassert>

class FloatArray {
public:
    FloatArray() : size_(0), data_(nullptr) {}

    explicit FloatArray(size_t n) : size_(n), data_(new float[n]()) {}

    // 1. Destructor
    ~FloatArray() noexcept {
        delete[] data_;
    }

    // 2. Copy Constructor (Deep copy)
    FloatArray(const FloatArray& other) : size_(other.size_), data_(other.size_ ? new float[other.size_] : nullptr) {
        if (data_) {
            std::copy(other.data_, other.data_ + size_, data_);
        }
    }

    // 3. Copy Assignment (Deep copy with self-assignment guard)
    FloatArray& operator=(const FloatArray& other) {
        if (this != &other) {
            float* new_data = other.size_ ? new float[other.size_] : nullptr;
            if (new_data) {
                std::copy(other.data_, other.data_ + other.size_, new_data);
            }
            delete[] data_;
            data_ = new_data;
            size_ = other.size_;
        }
        return *this;
    }

    // 4. Move Constructor
    FloatArray(FloatArray&& other) noexcept
        : size_(std::exchange(other.size_, 0)),
          data_(std::exchange(other.data_, nullptr)) {}

    // 5. Move Assignment
    FloatArray& operator=(FloatArray&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            size_ = std::exchange(other.size_, 0);
            data_ = std::exchange(other.data_, nullptr);
        }
        return *this;
    }

    size_t size() const noexcept { return size_; }
    float& operator[](size_t i) { return data_[i]; }
    const float& operator[](size_t i) const { return data_[i]; }

private:
    size_t size_;
    float* data_;
};

int main() {
    std::cout << "--- Drill 13: Full Rule of Five Implementation ---\n\n";

    FloatArray a(10);
    a[0] = 1.0f; a[9] = 9.0f;

    // Test Copy Constructor
    FloatArray b = a;
    b[0] = 99.0f;
    assert(a[0] == 1.0f && "Deep copy must not affect original!");

    // Test Copy Assignment
    FloatArray c;
    c = a;
    assert(c[9] == 9.0f);

    // Test Move Constructor
    FloatArray d = std::move(a);
    assert(a.size() == 0);
    assert(d.size() == 10);
    assert(d[9] == 9.0f);

    // Test Move Assignment
    FloatArray e;
    e = std::move(d);
    assert(d.size() == 0);
    assert(e.size() == 10);

    std::cout << "\n✓ Drill 13 Passed: Complete Rule of Five verified!\n";
    return 0;
}
