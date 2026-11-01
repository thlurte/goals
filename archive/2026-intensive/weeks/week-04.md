# Week 4: Inverted File (IVF), SQ4/SQ2 Strided Bit-Packing & FastScan
> **Dates**: November 9 – November 15, 2026  
> **Core Focus**: Inverted File (IVF) index routing, coarse Voronoi quantizers, SQ4/SQ2 strided bit-packing, and in-register FastScan distance evaluation.

---

### Day 22 (Mon, Nov 9): Inverted File (IVF) Index Architecture & Posting Lists
- 📖 **Reading**: **[Zezula et al.]** (Similarity Search: The Metric Space Approach) & FAISS IVF documentation.
- 💻 **Drills (`day_22_drills.md`)**:
  1. `drill_22a_ivf_posting_lists.cpp`: Implement `InvertedList` container: holds vector IDs and quantized codes contiguously.
  2. `drill_22b_coarse_quantizer_routing.cpp`: Train $n_{\text{list}}=64$ coarse centroids via k-means. Given a query vector, score coarse centroids and select top-$n_{\text{probe}}$ lists to search.
  3. `drill_22c_ivf_recall_vs_nprobe.cpp`: Benchmark Recall vs $n_{\text{probe}} \in \{1, 2, 4, 8, 16\}$ on 50,000 vectors. Measure the prune ratio.
- 🛠️ **`secan`**: Design `secan/include/secan/index/ivf/ivf_index.hpp`.

---

### Day 23 (Tue, Nov 10): SQ4 & SQ2 Strided Bit-Packing Mechanics
- 📖 **Reading**: Sub-byte quantization: 4-bit nibbles (values $0..15$) and 2-bit codes ($0..3$). Strided memory layouts for SIMD register streaming.
- 💻 **Drills (`day_23_drills.md`)**:
  1. `drill_23a_sq4_nibble_packing.cpp`: Pack two 4-bit scalar values into a single `uint8_t`: `byte = (val1 & 0x0F) | ((val2 & 0x0F) << 4)`. Write unpacker.
  2. `drill_23b_sq2_bit_packing.cpp`: Pack four 2-bit values into a single `uint8_t`. Write bit-shift extraction and verify roundtrip precision.
  3. `drill_23c_strided_simd_layout.cpp`: Reorder $N=32$ vectors into a **strided 32-byte layout**: byte $i$ holds the $k$-th dimension for vector $i$. This allows a single SIMD register to load dimension $k$ across all 32 vectors in 1 instruction.
- 🛠️ **`secan`**: Add `secan/include/secan/quantization/bit_packing.hpp`.

---

### Day 24 (Wed, Nov 11): AVX2 FastScan Engine with `vpshufb`
- 📖 **Reading**: **FastScan In-Register Lookups**: Mapping strided 4-bit codes to precalculated 16-entry LUTs using `_mm256_shuffle_epi8`.
- 💻 **Drills (`day_24_drills.md`)**:
  1. `drill_24a_fastscan_lut_quantization.cpp`: Precompute query distance to the 16 quantization bins ($0..15$) and scale to 8-bit unsigned integers. Load into `__m256i` LUT register.
  2. `drill_24b_fastscan_kernel_32vectors.cpp`: Scan 32 vectors simultaneously: load 32 bytes of strided codes, execute `_mm256_shuffle_epi8`, accumulate distances into `__m256i` accumulators using `_mm256_adds_epu8` or `_mm256_maddubs_epi16`.
  3. `drill_24c_fastscan_vs_standard_bench.cpp`: Benchmark AVX2 FastScan vs standard FP32 scan across 100,000 vectors. Witness a **4x to 8x throughput leap**.
- 🛠️ **`secan`**: Implement `secan/include/secan/search/fastscan_matcher.hpp`.

---

### Day 25 (Thu, Nov 12): Product Quantization (PQ) with FastScan
- 📖 **Reading**: **[Jégou et al. (2011)]** — Product Quantization with $M=16$ or $M=32$ subvectors and $K=16$ centroids per subvector (PQ4 / FastScan).
- 💻 **Drills (`day_25_drills.md`)**:
  1. `drill_25a_pq4_codebook_training.cpp`: Train $M=16$ subvector codebooks with $K=16$ centroids each.
  2. `drill_25b_pq4_strided_encoding.cpp`: Encode vectors into 4-bit indices and pack into strided 32-byte blocks.
  3. `drill_25c_pq_fastscan_eval.cpp`: Evaluate 32 vectors across $M=16$ subvectors using back-to-back `vpshufb` cycles without touching main memory during accumulation.
- 🛠️ **`secan`**: Combine Product Quantization with the FastScan engine in `secan`.

---

### Day 26 (Fri, Nov 13): Complete IVF-FastScan Index Integration
- 📖 **Reading**: End-to-end Inverted File FastScan traversal: Coarse Voronoi routing followed by in-register FastScan over target posting lists.
- 💻 **Drills (`day_26_drills.md`)**:
  1. `drill_26a_ivf_fastscan_build.cpp`: Build an `IVFFastScan` index: partition 100,000 vectors into 128 inverted lists, encode each list into strided 32-byte FastScan blocks.
  2. `drill_26b_ivf_fastscan_query.cpp`: Query the index: coarse centroid routing $\to$ generate 16-byte query LUT $\to$ stream posting lists with FastScan kernel.
  3. `drill_26c_topk_heap_accumulation.cpp`: Maintain a bounded max-heap of top-$k$ results across all scanned lists.
- 🛠️ **`secan`**: Full implementation of `secan::index::IVFFastScanIndex`.

---

### Day 27 (Sat, Nov 14): Accuracy, QPS & Compression Benchmarking
- 💻 **Drills (`day_27_drills.md`)**:
  1. `drill_27a_ivf_fastscan_benchmark.cpp`: Measure Recall@10, QPS, and memory footprint on SIFT1M subset.
  2. `drill_27b_memory_bandwidth_saturation.cpp`: Calculate memory bandwidth during scan. Prove that FastScan transitions the search from memory-bandwidth-bound to compute-bound.
  3. `drill_27c_pareto_frontier.cpp`: Generate a chart comparing Flat vs IVF-FP32 vs IVF-FastScan.
- 🛠️ **`secan`**: Add IVF-FastScan benchmarks to `secan/benchmarks/`.

---

### Day 28 (Sun, Nov 15): Timed IVF-FastScan Exam (No Notes)
- ⏱️ **45-minute timed coding exam**: Write an AVX2 `vpshufb` 32-vector FastScan kernel and strided bit unpacker from a blank file with zero compiler warnings.
