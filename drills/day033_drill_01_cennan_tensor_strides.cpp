// ==============================================================================
// 🥋 Cennan Drill 33.1: N-D Tensor Layouts, Strides, & Flat Pointer Indexing
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra day033_drill_01_cennan_tensor_strides.cpp -o drill33 && ./drill33
//
// CONTEXT:
// In the `cennan` neural network engine, multi-dimensional tensors are backed by
// contiguous 1D memory buffers. Mapping an N-D index (i_0, i_1, ..., i_{k-1}) to flat index
// requires computing row-major contiguous strides: stride[d] = prod_{j=d+1}^{k-1} shape[j].
//
// C++ CONCEPTS TO PRACTICE:
// 1. `std::vector<size_t>` shapes and strides calculation.
// 2. Transposed non-contiguous strides (zero-copy view).
// 3. Flat linear memory offset: offset = sum(indices[d] * strides[d]).
// ==============================================================================

#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

struct TensorView {
    std::vector<size_t> shape;
    std::vector<size_t> strides;
    float* data{nullptr};

    // TODO 1: Compute default contiguous row-major strides
    // For shape [N, C, H, W], stride[3] = 1, stride[2] = W, stride[1] = H * W, stride[0] = C * H * W
    static std::vector<size_t> compute_contiguous_strides(const std::vector<size_t>& shape) {
        std::vector<size_t> strides(shape.size());
        // [YOUR CODE HERE]
        return strides;
    }

    // TODO 2: Compute flat offset for an N-D coordinate index
    // offset = sum_{d=0}^{ndim-1} (indices[d] * strides[d])
    size_t get_offset(const std::vector<size_t>& indices) const {
        // [YOUR CODE HERE]
        return 0;
    }

    // Access element
    float& at(const std::vector<size_t>& indices) {
        return data[get_offset(indices)];
    }

    const float& at(const std::vector<size_t>& indices) const {
        return data[get_offset(indices)];
    }
};

int main() {
    std::cout << "--- Drill 33.1: Cennan Tensor Strides & Memory Layout ---\n\n";

    // Tensor shape: (2, 3, 4) -> Batch=2, Rows=3, Cols=4 (Total = 24 elements)
    std::vector<size_t> shape = {2, 3, 4};
    auto strides = TensorView::compute_contiguous_strides(shape);

    std::cout << "Computed Strides for (2, 3, 4): ["
              << strides[0] << ", " << strides[1] << ", " << strides[2] << "]\n";

    assert(strides[2] == 1 && strides[1] == 4 && strides[0] == 12 && "Contiguous stride mismatch!");

    std::vector<float> buffer(24);
    for (size_t i = 0; i < 24; ++i) buffer[i] = static_cast<float>(i);

    TensorView tensor{shape, strides, buffer.data()};

    // Element at (1, 2, 3) -> 1 * 12 + 2 * 4 + 3 * 1 = 12 + 8 + 3 = 23
    size_t offset = tensor.get_offset({1, 2, 3});
    std::cout << "Offset for (1, 2, 3): " << offset << " (Expected: 23)\n";
    assert(offset == 23 && "Offset calculation mismatch!");
    assert(tensor.at({1, 2, 3}) == 23.0f);

    std::cout << "\n✓ Drill Passed: Tensor contiguous stride calculation and flat indexing verified!\n";
    return 0;
}
