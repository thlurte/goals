# 🥋 Daily Systems, Engines & Deep Learning Drills

Targeted, hands-on micro-drills designed to build instinctual engineering reflexes across:
1. **🌙 `secan` Vector Search Engine (C++20/SIMD)**: Quantization (SQ8/SQ4/PQ/BQ), AVX2 integer dot products, cache alignment (`alignas(64)`), zero-allocation `std::span` views, inverted indexing, and POPCNT Hamming distance.
2. **🌙 `cennan` Neural Engine (C++20)**: N-D contiguous tensor strides, manual analytical backward passes (Linear/ReLU/Loss), and C++ Directed Acyclic Graph (DAG) reverse-mode automatic differentiation.
3. **☀️ Morning Builder Track (Python/PyTorch from scratch)**: Scalar computational graph engine (Micrograd), Rotary Position Embeddings (RoPE), Vision Transformer (ViT) patch projections, custom AdamW optimizer with decoupled weight decay, and InfoNCE in-batch contrastive loss.

---

## 🌙 `secan` C++ Vector Search & SIMD Drills

| Day | Drill | Title | Key C++ Systems Concepts | File |
|:---:|:---:|:---|:---|:---|
| **10** | **10.1** | MXCSR FTZ/DAZ Modes | Denormals, microcode traps, `_MM_SET_FLUSH_ZERO_MODE` | [`day010_drill_01_mxcsr_ftz_daz.cpp`](day010_drill_01_mxcsr_ftz_daz.cpp) |
| **10** | **10.2** | SIMD Load & FMA Operations | `_mm256_loadu_ps`, `_mm256_fmadd_ps`, 8-lane math | [`day010_drill_02_simd_fma_load.cpp`](day010_drill_02_simd_fma_load.cpp) |
| **11** | **11.1** | Pointer Offset & Flat Indexing | Row-major layout `(i * D + j)`, pointer arithmetic | [`day011_drill_01_pointer_offset.cpp`](day011_drill_01_pointer_offset.cpp) |
| **11** | **11.2** | Dual Accumulator Unrolling | Breaking dependency chains, ILP, FMA port saturation | [`day011_drill_02_dual_accumulator.cpp`](day011_drill_02_dual_accumulator.cpp) |
| **11** | **11.3** | SIMD Chunk & Tail Loop | 8-float chunks, remainder scalar cleanup | [`day011_drill_03_chunk_tail_loop.cpp`](day011_drill_03_chunk_tail_loop.cpp) |
| **11** | **11.4** | In-Place L2 Normalization | Unit vector scaling, epsilon guard | [`day011_drill_04_normalize_inplace.cpp`](day011_drill_04_normalize_inplace.cpp) |
| **12** | **12.1** | Fused 1-Pass Cosine Distance | Computing dot product and norms in single loop | [`day012_drill_01_fused_cosine.cpp`](day012_drill_01_fused_cosine.cpp) |
| **12** | **12.2** | Peak Single-Core GFLOPS | Calculating execution port saturation on Zen 4 | [`day012_drill_02_peak_gflops.cpp`](day012_drill_02_peak_gflops.cpp) |
| **12** | **12.3** | Fused vs 2-Pass Memory Traffic | Halving memory bus load traffic (50% reduction) | [`day012_drill_03_pass_comparison.cpp`](day012_drill_03_pass_comparison.cpp) |
| **24** | **24.1** | Cache Isolation (`alignas(64)`) | Preventing MESI false sharing in concurrent lists | [`day024_drill_01_cache_alignment.cpp`](day024_drill_01_cache_alignment.cpp) |
| **25** | **25.1** | Spherical $k$-Means Projection | Unit hypersphere projection for Cosine/MIPS | [`day025_drill_01_spherical_projection.cpp`](day025_drill_01_spherical_projection.cpp) |
| **26** | **26.1** | `std::partial_sort` Routing | $O(K \log P)$ centroid selection vs $O(K \log K)$ waste | [`day026_drill_01_partial_sort_routing.cpp`](day026_drill_01_partial_sort_routing.cpp) |
| **26** | **26.2** | Bounded Max-Heap Top-K | Zero-allocation streaming $O(N \log K)$ neighbor heap | [`day026_drill_02_bounded_heap.cpp`](day026_drill_02_bounded_heap.cpp) |
| **27** | **27.1** | Software Prefetching (`_mm_prefetch`) | L1/L2 cache preloading across 64-byte strides | [`day027_drill_01_cache_stride_prefetch.cpp`](day027_drill_01_cache_stride_prefetch.cpp) |
| **28** | **28.1** | C++20 `std::span` Zero-Alloc Views | Non-owning pointer+size views over arbitrary buffers | [`day028_drill_01_span_zero_alloc.cpp`](day028_drill_01_span_zero_alloc.cpp) |
| **31** | **31.1** | SQ8 Percentile Clipping | `std::span`, `const` correctness, `std::clamp`, outlier rejection | [`day031_drill_01_sq8_clipping.cpp`](day031_drill_01_sq8_clipping.cpp) |
| **32** | **32.1** | AVX2 SQ8 Dot Product | `_mm256_cvtepu8_epi16`, `_mm256_madd_epi16`, width casting | [`day032_drill_01_sq8_avx2_dot.cpp`](day032_drill_01_sq8_avx2_dot.cpp) |
| **34** | **34.1** | SQ4 Nibble Bit-Packing | Bitwise `&`, `|`, shifts (`<<`, `>>`), 64B cache line fitting | [`day034_drill_01_sq4_packing.cpp`](day034_drill_01_sq4_packing.cpp) |
| **35** | **35.1** | Two-Stage Re-ranking | Struct `operator<`, `std::partial_sort`, coarse SQ8 -> fine FP32 | [`day035_drill_01_twostage_filter.cpp`](day035_drill_01_twostage_filter.cpp) |
| **38** | **38.1** | Subspace $k$-Means Clustering | Multi-dim flattening, `std::fill`, inverse division, L1D locality | [`day038_drill_01_subspace_kmeans.cpp`](day038_drill_01_subspace_kmeans.cpp) |
| **40** | **40.1** | Asymmetric Distance (ADC) | Precomputed 2D LUT, 4-way loop unrolling, IPC saturation | [`day040_drill_01_adc_unroll.cpp`](day040_drill_01_adc_unroll.cpp) |
| **41** | **41.1** | 1-Bit Binary Quantization (BQ) | `__builtin_popcountll`, 64-bit integer bitmasks, POPCNT | [`day041_drill_01_bq_popcount.cpp`](day041_drill_01_bq_popcount.cpp) |
| **42** | **42.1** | Composed IVF-PQ Scan | Inverted list structs, two-level routing, query ADC scanning | [`day042_drill_01_composed_ivfpq.cpp`](day042_drill_01_composed_ivfpq.cpp) |

---

## 🌙 `cennan` C++ Neural Engine & Autodiff Drills

| Day | Drill | Title | Key C++ Neural Engine Concepts | File |
|:---:|:---:|:---|:---|:---|
| **33** | **33.1** | Tensor Strides & Memory Layout | Row-major contiguous stride computation, flat offset mapping | [`day033_drill_01_cennan_tensor_strides.cpp`](day033_drill_01_cennan_tensor_strides.cpp) |
| **36** | **36.1** | Linear Forward & Analytical Backward | $Y = XW^T + b$, $dX = dY W$, $dW = dY^T X$, $db = \sum dY$ | [`day036_drill_01_cennan_linear_backward.cpp`](day036_drill_01_cennan_linear_backward.cpp) |
| **39** | **39.1** | C++ DAG Autograd Engine | `std::shared_ptr<Node>`, closures, topological DFS backward | [`day039_drill_01_cennan_autograd_graph.cpp`](day039_drill_01_cennan_autograd_graph.cpp) |

---

## ☀️ Morning Builder Track: Deep Learning Drills (Python)

| Day | Drill | Title | Deep Learning Architecture & Algorithmic Concepts | File |
|:---:|:---:|:---|:---|:---|
| **24** | **24.1** | Scalar Autograd Engine (Micrograd) | Dynamic graph building, topological reverse DFS autodiff | [`day024_builder_drill_01_micrograd_autograd.py`](day024_builder_drill_01_micrograd_autograd.py) |
| **25** | **25.1** | Rotary Position Embeddings (RoPE) | Inverse frequencies, 2D pairwise query/key rotation | [`day025_builder_drill_01_rope_attention.py`](day025_builder_drill_01_rope_attention.py) |
| **32** | **32.1** | ViT Patch Embedding & [CLS] Token | Conv2d patch projection, CLS concatenation, 1D pos embed | [`day032_builder_drill_01_vit_patch_embed.py`](day032_builder_drill_01_vit_patch_embed.py) |
| **37** | **37.1** | AdamW Optimizer from Scratch | 1st/2nd moments EMA, bias correction, decoupled weight decay | [`day037_builder_drill_01_adamw_scratch.py`](day037_builder_drill_01_adamw_scratch.py) |
| **38** | **38.1** | InfoNCE In-Batch Contrastive Loss | Cosine similarity matrix, in-batch negatives, temperature $\tau$ | [`day038_builder_drill_01_infonce_inbatch.py`](day038_builder_drill_01_infonce_inbatch.py) |

---

## 💡 How to Practice & Verify

### 1. Run Interactive Practice Drills
Each drill contains empty `// [YOUR CODE HERE]` or `# [YOUR CODE HERE]` sections with guided hints:
* **C++ Drills**:
  ```bash
  g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra day031_drill_01_sq8_clipping.cpp -o drill && ./drill
  ```
* **Python DL Drills**:
  ```bash
  python3 day032_builder_drill_01_vit_patch_embed.py
  ```

### 2. Cross-Check Reference Solutions
Full working reference implementations are stored in [`solutions/`](solutions/):
```bash
python3 solutions/day037_builder_drill_01_adamw_scratch.py
g++ -O3 -std=c++20 solutions/day036_drill_01_cennan_linear_backward.cpp -o sol36 && ./sol36
```

---

