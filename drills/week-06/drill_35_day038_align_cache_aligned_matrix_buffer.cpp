// ==============================================================================
// 🥋 Drill: Production 64-Byte Cache-Aligned 2D Vector Matrix Storage
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Rule of 5)
// - Agner Fog: Optimizing Software in C++ (Ch 8: Dynamic Memory Allocation)
//
// 🎯 CORE LESSON:
// 1. Allocates $N \times \text{pitch}$ floats aligned to 64 bytes using `posix_memalign`.
// 2. Guarantees that row pointer `row_ptr(i)` is always 64-byte aligned for zero-penalty SIMD.
// 3. Implements Rule of 5 to prevent memory leaks and double-free hazards.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_35_day038_align_cache_aligned_matrix_buffer.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <utility>
#include <cassert>

class AlignedMatrix {
public:
    AlignedMatrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
        // Pad cols up to multiple of 16 floats (64 bytes)
        size_t rem = cols % 16;
        pitch_ = (rem == 0) ? cols : (cols + (16 - rem));
        size_t bytes = rows_ * pitch_ * sizeof(float);

        void* ptr = nullptr;
        int ret = posix_memalign(&ptr, 64, bytes);
        if (ret != 0) throw std::bad_alloc();
        data_ = static_cast<float*>(ptr);
    }

    ~AlignedMatrix() noexcept {
        std::free(data_);
    }

    AlignedMatrix(const AlignedMatrix&) = delete;
    AlignedMatrix& operator=(const AlignedMatrix&) = delete;

    AlignedMatrix(AlignedMatrix&& other) noexcept
        : rows_(std::exchange(other.rows_, 0)),
          cols_(std::exchange(other.cols_, 0)),
          pitch_(std::exchange(other.pitch_, 0)),
          data_(std::exchange(other.data_, nullptr)) {}

    AlignedMatrix& operator=(AlignedMatrix&& other) noexcept {
        if (this != &other) {
            std::free(data_);
            rows_ = std::exchange(other.rows_, 0);
            cols_ = std::exchange(other.cols_, 0);
            pitch_ = std::exchange(other.pitch_, 0);
            data_ = std::exchange(other.data_, nullptr);
        }
        return *this;
    }

    float* row(size_t r) noexcept { return data_ + r * pitch_; }
    const float* row(size_t r) const noexcept { return data_ + r * pitch_; }
    size_t pitch() const noexcept { return pitch_; }

private:
    size_t rows_;
    size_t cols_;
    size_t pitch_;
    float* data_;
};

int main() {
    std::cout << "--- Drill 35: 64-Byte Cache-Aligned Matrix Storage ---\n\n";

    AlignedMatrix mat(100, 130);
    assert(mat.pitch() == 144); // 130 padded to 144

    for (size_t r = 0; r < 100; ++r) {
        uintptr_t addr = reinterpret_cast<uintptr_t>(mat.row(r));
        assert(addr % 64 == 0 && "Every single matrix row must be 64-byte aligned!");
    }

    std::cout << "All 100 rows verified 64-byte aligned for AVX-512 / Cache lines!\n";
    std::cout << "\n✓ Drill 35 Passed: Aligned Matrix storage verified!\n";
    return 0;
}
