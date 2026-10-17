// ==============================================================================
// 🥋 Drill: The Double-Free Trap: Shallow Copy vs Deep Copy
//
// 📖 READING SOURCES:
// - Meyers: Effective C++ (Item 14: Think carefully about copying behavior in resource-managing classes)
// - C++ Core Guidelines: C.20 (If you can avoid defining default operations, do)
//
// 🎯 CORE LESSON:
// 1. Compiler-generated default copy constructor copies raw pointers shallowly.
// 2. When both objects go out of scope, both destructors call `delete[]` on the identical pointer address.
// 3. The fix is either deleting copy operations (`= delete`) or allocating fresh memory (deep copy).
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_52_day038_mem_double_free_trap_and_fix.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstring>
#include <cassert>

class SafeVectorBuffer {
public:
    explicit SafeVectorBuffer(size_t n) : size_(n), data_(new float[n]()) {}
    ~SafeVectorBuffer() noexcept { delete[] data_; }

    // Fix: Explicit deep copy constructor
    SafeVectorBuffer(const SafeVectorBuffer& other)
        : size_(other.size_), data_(new float[other.size_]) {
        std::memcpy(data_, other.data_, size_ * sizeof(float));
    }

    // Fix: Explicit deep copy assignment with self-assignment guard
    SafeVectorBuffer& operator=(const SafeVectorBuffer& other) {
        if (this != &other) {
            float* new_data = new float[other.size_];
            std::memcpy(new_data, other.data_, other.size_ * sizeof(float));
            delete[] data_;
            data_ = new_data;
            size_ = other.size_;
        }
        return *this;
    }

    size_t size() const noexcept { return size_; }
    float* data() noexcept { return data_; }

private:
    size_t size_;
    float* data_;
};

int main() {
    std::cout << "--- Drill 52: Double-Free Prevention via Deep Copy ---\n\n";

    SafeVectorBuffer a(16);
    a.data()[0] = 42.0f;

    {
        // Copy construction
        SafeVectorBuffer b = a;
        assert(b.data() != a.data() && "Deep copy must create a distinct heap allocation!");
        assert(b.data()[0] == 42.0f);
        b.data()[0] = 99.0f;
        assert(a.data()[0] == 42.0f);
    } // b destroyed cleanly without double-freeing a.data()

    assert(a.data()[0] == 42.0f);
    std::cout << "\n✓ Drill 52 Passed: Deep copy prevented double-free crash!\n";
    return 0;
}
