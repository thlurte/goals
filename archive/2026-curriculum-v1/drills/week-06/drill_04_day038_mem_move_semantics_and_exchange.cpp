// ==============================================================================
// 🥋 Drill: Move Semantics & Pointer Pilfering via std::exchange
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 14: Declare functions noexcept if they won't emit exceptions)
// - Meyers: Effective Modern C++ (Item 17: Understand special member function generation)
//
// 🎯 CORE LESSON:
// 1. Move constructors and move assignments pilfer resources from the donor object.
// 2. `std::exchange(source, replacement)` sets source to replacement and returns old value in one step.
// 3. Always leave moved-from objects in a valid, destructible state (pointer = nullptr) to prevent double-free.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_04_day038_mem_move_semantics_and_exchange.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <utility>
#include <cassert>
#include <cstddef>

class VectorBuffer {
public:
    explicit VectorBuffer(size_t count) : count_(count), data_(new float[count]()) {}

    ~VectorBuffer() noexcept {
        delete[] data_;
    }

    // Non-copyable
    VectorBuffer(const VectorBuffer&) = delete;
    VectorBuffer& operator=(const VectorBuffer&) = delete;

    // Move constructor
    VectorBuffer(VectorBuffer&& other) noexcept
        : count_(std::exchange(other.count_, 0)),
          data_(std::exchange(other.data_, nullptr)) {}

    // Move assignment
    VectorBuffer& operator=(VectorBuffer&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            count_ = std::exchange(other.count_, 0);
            data_ = std::exchange(other.data_, nullptr);
        }
        return *this;
    }

    size_t count() const noexcept { return count_; }
    float* data() noexcept { return data_; }
    const float* data() const noexcept { return data_; }

private:
    size_t count_{0};
    float* data_{nullptr};
};

int main() {
    std::cout << "--- Drill 04: Move Semantics & std::exchange ---\n\n";

    VectorBuffer a(128);
    a.data()[0] = 3.14f;

    // Test move constructor
    VectorBuffer b = std::move(a);
    assert(a.data() == nullptr);
    assert(a.count() == 0);
    assert(b.count() == 128);
    assert(b.data() != nullptr);
    assert(b.data()[0] == 3.14f);

    // Test move assignment
    VectorBuffer c(64);
    c = std::move(b);
    assert(b.data() == nullptr);
    assert(b.count() == 0);
    assert(c.count() == 128);
    assert(c.data()[0] == 3.14f);

    std::cout << "\n✓ Drill 04 Passed: Move semantics with std::exchange verified!\n";
    return 0;
}
