# Hard landings & ledgers

> Required VS / DL / deferred landings. Week tables: [`weeks/`](weeks/). Curriculum index: [`README.md`](README.md).

## Evidence required at every systems landing

A landing is complete only when its implementation has an oracle check, run manifest, raw JSON/CSV, parameter sweep with a Pareto/latency plot, and a short evidence-backed interpretation. Comparable algorithms must also have a matched-quality external baseline by Week 12. The shared result format and weekly close rule live in the [empirical benchmarking track](../research/README.md#benchmark-contract-what-makes-work-showcaseable).

## Deferred-work ledger (slimmed → hard landing)

Nothing slimmed is optional. Every row is **required** on the landing week.

| Slimmed from | What was cut | **Hard landing (required)** | Why there |
|:---|:---|:---|:---|
| **Week 8** | HNSW bounded flat heap + bitset visited | **Week 12 Wed** | Before composed-index Pareto |
| **Week 10** | **SINDI** + BM25 + Block-Max WAND + **RRF** | **Week 16 Fri** | Hybrid IR (Learned Sparse & Lexical) |
| **Week 11** | DiskANN `io_uring` + **Vamana prune** | **Week 16 Thu** | Graph construction, not only SSD fetch |
| **Week 15** | FlashAttention-2 | **Week 25** | GPU block |
| **Week 7→10** | RaBitQ (after QR) | **Week 10 Thu** | Already required |
| **Week 8→12** | Whitening / query-side PCA | **Week 12 Mon** | After SVD |
| *(frontier)* | ACORN + tombstones + NUMA + **pre/post/range** | **Week 22** | On-call filters |

## Core C++ Engine Hard Landings: `secan` & `cennan`

The dual-engine C++ architecture consists of [`secan`](https://github.com/thlurte/secan) (Vector Search & Indexing Engine) and [`cennan`](https://github.com/thlurte/cennan) (Embedding & Latent Representation Engine).

### 1. `secan` Retrieval & Indexing Engine Landings
*REST out of scope. Multi-threaded C++20 / SIMD / GPU.*

| Milestone / Capability | Target Landing | Microarchitectural Mechanism / Evidence |
|:---|:---|:---|
| **Randomized KD-Trees (FLANN baseline)** | **Week 3 Fri** | Best-Bin-First vs Brute Force baseline ($D=128$) |
| **Spherical $k$-Means & IVF-Flat Index** | **Week 4 Thu–Fri** | Multi-probe Voronoi routing + `alignas(64)` inverted lists |
| **Scalar Quantization (SQ8) & ADC** | **Week 5 Wed** | $4\times$ memory shrink + AVX2 asymmetric distance kernel |
| **AVX-512 VNNI INT8 & Hamming Kernels** | **Week 5 Thu** | `_mm512_dpbusd_epi32` (4x throughput) & `_mm512_popcnt_epi64` |
| **4-Bit Scalar Quantization (SQ4)** | **Week 5 Thu** | Nibble packing + 2-stage SQ8 $\to$ FP32 candidate re-ranker |
| **Asymmetric PQ / FastScan PSHUFB** | **Week 6 Fri** | 4-bit LUT shuffle distance in single clock cycle |
| **Optimized PQ (OPQ) & Residual PQ** | **Week 7 Fri** | Covariance alignment rotation to minimize quantization MSE |
| **768-D Text Recall@10 vs QPS Sweep** | **Week 8 Fri** | Golden pre-staged `.fvecs` + DL model parity |
| **Batch HNSW Graph Construction** | **Week 9 Mon–Tue** | PiPNN HashPrune + Fast GEMM Graph Construction |
| **MUVERA FDE & MaxSim Re-ranker** | **Week 10 Mon–Wed** | Fixed-Dimensional Encoding $\to$ IP MIPS $\to$ MaxSim vs PLAID |
| **TurboQuant 1@k vs RaBitQ/PQ** | **Week 10 Fri** | 1-bit polar quantization comparison on GloVe / 768-D |
| **Composed `IVFPQIndex` + `HNSWSQIndex`** | **Week 12 Thu–Fri** | Pareto frontier vs Faiss/hnswlib on SIFT1M & 768-D |
| **DiskANN / Vamana Graph + `io_uring`** | **Week 16 Thu** | $\alpha$-pruning + compressed RAM tier + NVMe asynchronous I/O |
| **Hybrid IR (SINDI + BM25 + RRF)** | **Week 16 Fri** | Block-Max WAND + Reciprocal Rank Fusion ($\alpha$-tuned) |
| **ACORN Filtered Graph Search** | **Week 22 Mon + Fri** | Multi-label predicate filtering + range queries |

---

### 2. `cennan` C++ Embedding & Inference Engine Landings
*Pure C++20 forward inference runtime feeding embeddings with zero copy into `secan`.*

| Milestone / Capability | Target Landing | Implementation / Verification Deliverable |
|:---|:---|:---|
| **Zero-Copy POSIX `MMapLoader`** | **Week 4 Mon** | `madvise` page hints (`MADV_SEQUENTIAL`) + slice views |
| **Vectorized Normalizations (`norm.h`)** | **Week 4 Wed** | AVX2+FMA `RMSNorm` (LLaMA) & `LayerNorm` (BERT/ViT) |
| **Vectorized In-Place Activations (`activations.h`)** | **Week 5 Wed** | `gelu_inplace` (tanh approx) + `swiglu_forward` + `silu` |
| **Register-Blocked GEMM (`gemm.h`)** | **Week 5 Fri** | 2D register-blocked $4 \times 16$ unrolled AVX2+FMA GEMM |
| **Safetensors 8-Byte JSON Header Parser** | **Week 6 Tue** | Zero-copy weight tensor ingestion from `.safetensors` |
| **Standalone C++ Tokenizer (`tokenizer/`)** | **Week 7 Tue** | Standalone C++ WordPiece & BPE tokenizer |
| **C++ Dense Bi-Encoder (MiniLM / BGE)** | **Week 8 Wed** | End-to-end text token $\to$ 768-D embedding pipeline |
| **In-SRAM Multi-Vector MaxSim Kernel** | **Week 9 Wed** | ColBERT v2 $[B, L, D]$ late interaction in L1/L2 cache |
| **Vision Transformer Patch Embedder** | **Week 11 Wed** | C++ patch extraction & projection for ViT/ColPali |

---

## Deep Learning Track Landings (Tue & Wed Mornings 06:30–08:30)

| Week | DL Architecture & Implementation (Tue & Wed Mornings 06:30–08:30) |
|:---|:---|
| **W1 (Tue Sep 8 / Wed Sep 9)** | SDPA + causal mask (`uv init transformers-pytorch`) & unit tests |
| **W2 (Tue Sep 15 / Wed Sep 16)** | MHA + **GQA**; Pre-LN vs Post-LN |
| **W3 (Tue Sep 22 / Wed Sep 23)** | **Micrograd autograd engine** (~150 lines) + Pre-LN encoder + FFN + manual `backward()` for `Linear` |
| **W4 (Tue Sep 29 / Wed Sep 30)** | **RoPE + SwiGLU + CausalLM + CE + naive KV** + **SGD from scratch** (momentum, verify vs `torch.optim.SGD`) |
| **W5 (Tue Oct 6 / Wed Oct 7)** | **Vision Transformer (ViT)** patch embed + `[CLS]` + Pre-LN block |
| **W6 (Tue Oct 13 / Wed Oct 14)** | BERT + **InfoNCE** + **in-batch negatives** + **hard negative mining** (BM25 top-100); **AdamW from scratch**; export 768-D `.fvecs` for Week 8 Fri |
| **W7 (Tue Oct 20 / Wed Oct 21)** | Matryoshka Representation Learning (MRL) loss & dynamic dimension slicing |
| **W8 (Tue Oct 27 / Wed Oct 28)** | MRL / Anisotropic Projection Evaluation & Embedding Geometry Diagnostics |
| **W9 (Tue Nov 3 / Wed Nov 4)** | ColBERT + MaxSim + tiny Margin MSE + **knowledge distillation** (cross-encoder → bi-encoder) |
| **W12 (Tue Nov 24 / Wed Nov 25)** | **ONNX required**: InfoNCE bi-encoder → ONNX → **ORT**; PyTorch parity; emit 768-D `.fvecs` → `secan` |
| **W15 (Tue Dec 15 / Wed Dec 16)** | Online softmax (FA-1 math) & CUDA kernel foundations |
| **W21 (Tue Jan 26 / Wed Jan 27)** | CLIP projector + ColPali head |
| **W23 (Tue Feb 9 / Wed Feb 10)** | Stretch: re-run same ORT graph on ARM host (with NEON week) |
| **Remaining Weeks** | Continuous transformer scaling, multi-modal tokenization, and GPU inference pipelines |


---
---
