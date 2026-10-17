// ==============================================================================
// 🥋 Cennan Drill 33.1: Solution
// ==============================================================================

#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

struct TensorView {
    std::vector<size_t> shape;
    std::vector<size_t> strides;
    float* data{nullptr};

    static std::vector<size_t> compute_contiguous_strides(const std::vector<size_t>& shape) {
        std::vector<size_t> strides(shape.size());
        if (shape.empty()) return strides;

        size_t acc = 1;
        for (int d = static_cast<int>(shape.size()) - 1; d >= 0; --d) {
            strides[d] = acc;
            acc *= shape[d];
        }
        return strides;
    }

    size_t get_offset(const std::vector<size_t>& indices) const {
        size_t offset = 0;
        for (size_t d = 0; d < indices.size(); ++d) {
            offset += indices[d] * strides[d];
        }
        return offset;
    }

    float& at(const std::vector<size_t>& indices) {
        return data[get_offset(indices)];
    }

    const float& at(const std::vector<size_t>& indices) const {
        return data[get_offset(indices)];
    }
};

int main() {
    std::cout << "--- Drill 33.1: Cennan Tensor Strides (Solution) ---\n\n";

    std::vector<size_t> shape = {2, 3, 4};
    auto strides = TensorView::compute_contiguous_strides(shape);

    std::cout << "Computed Strides for (2, 3, 4): ["
              << strides[0] << ", " << strides[1] << ", " << strides[2] << "]\n";

    assert(strides[2] == 1 && strides[1] == 4 && strides[0] == 12 && "Contiguous stride mismatch!");

    std::vector<float> buffer(24);
    for (size_t i = 0; i < 24; ++i) buffer[i] = static_cast<float>(i);

    TensorView tensor{shape, strides, buffer.data()};

    size_t offset = tensor.get_offset({1, 2, 3});
    std::cout << "Offset for (1, 2, 3): " << offset << " (Expected: 23)\n";
    assert(offset == 23 && "Offset calculation mismatch!");
    assert(tensor.at({1, 2, 3}) == 23.0f);

    std::cout << "\n✓ Drill Passed: Tensor contiguous stride calculation and flat indexing verified!\n";
    return 0;
}
