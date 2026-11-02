# 2-Month Systems Mastery Curriculum (Nov 2 – Dec 31, 2026)

This roadmap outlines the focused, daily engineering schedule across C++ systems mastery, PyTorch transformer internals, weekend mathematics, and applied engine integration for [`secan`](https://github.com/thlurte/secan) (Vector Search Engine) and [`cennan`](https://github.com/thlurte/cennan) (Neural Inference Engine).

---

## ⏱️ Daily Rhythm & Allocation

| Day Type | Daily Total | Track Allocation |
| :--- | :--- | :--- |
| **Weekdays (Mon – Fri)** | **~4.0 Hours** | **2.0h** C++ Drills (`drills/`)<br>**1.0h** PyTorch Transformer Internals<br>**1.0h** Applied Engine Work (`secan` or `cennan`) |
| **Weekends (Sat – Sun)** | **~5.5 Hours** | **3.0h** Mathematics Sanctuary<br>**2.5h** Systems Profiling & End-to-End Lab |

---

## 📅 Month 1: C++ Specialization & Transformer Fundamentals (Nov 2026)

### Week 1 (Nov 2 – Nov 8): Memory Architecture & Custom Allocators
* **💻 C++ Drills ([`drills/memory/`](../../drills/drills/memory/))**:
  * [x] `01_monotonic_bump_allocator.md` — Power-of-two bitwise alignment, $O(1)$ bump allocation, bulk reset.
  * [x] `02_chained_chunk_arena.md` — Dynamic chunk growth, pointer stability, zero fragmentation.
  * [x] `03_freelist_slab_pool.md` — Embedded intrusive singly-linked list for uniform $O(1)$ allocations.
  * [x] `04_cacheline_aligned_allocator.md` — 64-byte AVX-512 alignment, STL vector integration.
  * [x] `05_std_pmr_custom_resource.md` — Polymorphic memory resource (`std::pmr::memory_resource`).
* **🧠 PyTorch Transformer Track**:
  * Deconstruct Multi-Head Attention (MHA) from scratch.
  * Implement Scaled Dot-Product Attention: $Q K^T / \sqrt{d_k}$, additive/boolean masking, Softmax stability.
* **📐 Weekend Math Sanctuary (Nov 7–8)**:
  * **Matrix Calculus**: Gradients of matrix products, trace calculus, Jacobian of vector-matrix mappings.
  * Analytical derivation of the Softmax derivative: $\frac{\partial S_i}{\partial z_j} = S_i (\delta_{ij} - S_j)$ and the Vector-Jacobian Product (VJP).
* **⚙️ Engine Integration**:
  * [`secan`](https://github.com/thlurte/secan): Replace raw allocations in posting list creation with `ChainedArenaAllocator`.
  * [`cennan`](https://github.com/thlurte/cennan): Introduce scratchpad arena for intermediate activation tensors during forward pass.

---

### Week 2 (Nov 9 – Nov 15): Object Lifecycle, Move Semantics & Exception Safety
* **💻 C++ Drills (`drills/lifecycle/`)**:
  * `01_rule_of_five_deep_and_move.md` — Value categories ($lvalue, rvalue, xvalue$), custom move semantics, invariants.
  * `02_perfect_forwarding_and_emplace.md` — Forwarding references, `std::forward`, in-place emplacing.
  * `03_raii_exception_guards.md` — Scope guards, transactional rollbacks under `std::bad_alloc`.
  * `04_type_erasure_any_view.md` — Non-owning view abstractions without virtual table dispatch overhead.
  * `05_transactional_commit_rollback.md` — Copy-and-swap, atomic pointer exchange for concurrent readers.
* **🧠 PyTorch Transformer Track**:
  * Positional Encodings:
    * Absolute sinusoidal positional encoding (Vaswani et al.).
    * Learnable position embeddings (BERT).
    * Rotary Position Embeddings (RoPE) — complex multiplication, rotary matrix formulation.
* **📐 Weekend Math Sanctuary (Nov 14–15)**:
  * **High-Dimensional Vector Geometry**:
    * Metric space foundations ($L_2$, Inner Product, Cosine similarity).
    * Concentration of measure on the unit hypersphere $\mathcal{S}^{d-1}$.
    * Distribution of pairwise angles and distances as dimension $d \to \infty$.
* **⚙️ Engine Integration**:
  * [`secan`](https://github.com/thlurte/secan): Exception-safe RAII transactional commit guards for incremental index mutations.
  * [`cennan`](https://github.com/thlurte/cennan): Zero-copy tensor slicing and view lifecycle semantics.

---

### Week 3 (Nov 16 – Nov 22): Hardware-Level SIMD Vectorization
* **💻 C++ Drills (`drills/simd/`)**:
  * `01_horizontal_reductions_avx2.md` — Multi-lane sum reduction (`_mm256_hadd_ps`, shuffle + permute2f128).
  * `02_fma_gemm_microkernel_unrolling.md` — 256-bit Fused Multiply-Add (`_mm256_fmadd_ps`), 4-way unrolling.
  * `03_byte_shuffle_lookup_pshufb.md` — 4-bit nibble indexing via `_mm256_shuffle_epi8` in registers.
  * `04_vectorized_softmax_and_fast_exp.md` — Padé polynomial approximation for $e^x$, SIMD max subtraction.
  * `05_avx512_masked_kernels.md` — 512-bit registers, opmask registers (`_k0`–`_k7`), branchless conditional execution.
* **🧠 PyTorch Transformer Track**:
  * Feed-Forward Networks (FFN / MLP):
    * Standard 2-layer MLP with expansion factor 4.
    * Gated linear units: GeGLU and SwiGLU implementations.
    * Normalization variants: Pre-LN vs Post-LN vs RMSNorm.
* **📐 Weekend Math Sanctuary (Nov 21–22)**:
  * **Anisotropy & Embedding Geometry**:
    * Spectral decay of embedding covariance matrices.
    * The hubness problem in high dimensions: bad hubs and anti-hubs.
    * Analytical derivation of cosine similarity distribution under anisotropic covariance.
* **⚙️ Engine Integration**:
  * [`secan`](https://github.com/thlurte/secan): Optimize `FastScan` distance calculation kernel using unrolled 4-way `pshufb` lookups.
  * [`cennan`](https://github.com/thlurte/cennan): Implement AVX2 vectorized Softmax kernel with numerical stability max-subtraction.

---

### Week 4 (Nov 23 – Nov 29): Multithreading, Concurrency & Lock-Free Data Structures
* **💻 C++ Drills (`drills/concurrency/`)**:
  * `01_atomic_flags_and_spinlocks.md` — `std::atomic_flag`, test-and-set loops, exponential backoff, CPU pause (`_mm_pause`).
  * `02_memory_orders_acquire_release.md` — Synchronizes-with relationship, release-acquire pairs, reordering barriers.
  * `03_spsc_lockfree_ring_buffer.md` — SPSC circular queue, cacheline padding avoiding false sharing.
  * `04_work_stealing_thread_pool.md` — Per-thread deque, task stealing, synchronization using atomics.
  * `05_mpmc_bounded_queue.md` — Multi-Producer Multi-Consumer queue with ticket dispenser / sequence counters.
* **🧠 PyTorch Transformer Track**:
  * Transformer Block Assembly:
    * Assembling Attention + FFN + Residual connections + RMSNorm into a single, cohesive Transformer Layer.
    * Stacking $N$ layers to form the full Transformer backbone.
    * Verification against Hugging Face `BertEncoder` weights.
* **📐 Weekend Math Sanctuary (Nov 28–29)**:
  * **Quantization & Rate-Distortion Theory**:
    * Lloyd-Max quantization conditions: Centroid condition and Nearest-Neighbor condition.
    * Quantization noise and Signal-to-Quantization-Noise Ratio (SQNR).
    * Subspace decomposition error bounds in Product Quantization.
* **⚙️ Engine Integration**:
  * [`secan`](https://github.com/thlurte/secan): Parallel batch query dispatcher using a worker thread pool.
  * [`cennan`](https://github.com/thlurte/cennan): Multi-threaded batched forward inference for linear projections.

---

## 📅 Month 2: Search Algorithms & Modern Inference (Dec 2026)

### Week 5 (Dec 1 – Dec 7): Inverted Files & Advanced Quantization
* **💻 C++ Drills (`drills/search/`)**: SIMD k-means clustering, posting list compression, LUT generation, FastScan block readers, coarse centroid routing.
* **🧠 PyTorch Transformer Track**: Full BERT model architecture (`BertEmbeddings`, `BertSelfAttention`, `BertIntermediate`, `BertOutput`).
* **📐 Weekend Math Sanctuary (Dec 5–6)**: The Johnson-Lindenstrauss Lemma proof and Gaussian random projection distortion bounds.
* **⚙️ Engine Integration**: [`secan`](https://github.com/thlurte/secan) `IvfPqIndex` combining inverted lists with Product Quantization.

### Week 6 (Dec 8 – Dec 14): Graph Search Algorithms (HNSW)
* **💻 C++ Drills (`drills/search/`)**: Navigable Small World greedy search, hierarchical layer routing, heuristic neighbor pruning, visited bitsets, concurrent edge updates.
* **🧠 PyTorch Transformer Track**: ModernBERT architecture (unpadding, alternating attention, FlashAttention principles).
* **📐 Weekend Math Sanctuary (Dec 12–13)**: Small-world graph properties, clustering coefficients, and spectral gap expansion.
* **⚙️ Engine Integration**: [`secan`](https://github.com/thlurte/secan) `HnswIndex` graph construction and search.

### Week 7 (Dec 15 – Dec 21): Filtered Search & ModernBERT C++ Implementation
* **💻 C++ Drills (`drills/search/`)**: Predicate evaluation, SIMD bypass filtered search, zero-copy `mmap` index serialization.
* **🧠 PyTorch Transformer Track**: Weight extraction pipeline to unpadded binary files (`.bin` + `JSON` metadata).
* **📐 Weekend Math Sanctuary (Dec 19–20)**: Information theory for vector search (entropy bounds, Elias-Fano encoding, bit-packing limits).
* **⚙️ Engine Integration**: [`cennan`](https://github.com/thlurte/cennan) C++ `SelfAttention` kernel with multi-head projection and scaled dot product.

### Week 8 (Dec 22 – Dec 31): End-to-End Validation & Capstone Integration
* **💻 C++ Drills (`drills/search/`)**: Profiling harness, cache-miss analysis, latency percentiles ($p50, p95, p99$).
* **🧠 PyTorch / C++ Unification**: Parity verification between PyTorch ModernBERT and `cennan` inference ($< 10^{-4}$ tolerance).
* **📐 Weekend Math Sanctuary (Dec 26–27)**: Mathematical synthesis: from continuous high-dimensional embeddings to discrete quantized metric graphs.
* **⚙️ Engine Integration**: End-to-end pipeline: Text $\to$ `cennan` Tokenizer $\to$ Transformer Encoder $\to$ `secan` HNSW Vector Search.
