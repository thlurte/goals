# Month 7 — Mar (Weeks 25–28)

> Part of the [28-week curriculum](../README.md). Research: [`research/`](../../research/README.md).

| | |
|:---|:---|
| [← Month 6 — Feb](month-06-feb.md) | [Essays →](../essays.md) |

---

# 📅 MONTH 7: GPU Specialization Closeout (Mar 2027)

> **🔬 Monthly research**: *Unified IO-Aware GPU Architecture for Vector Retrieval and LLM Attention Serving: FlashAttention-2, Paged KV Caches, and Multi-GPU Scaling* → publish **Fri Mar 12** · folder `research/2027-03-gpu-serving/`

---

### Week 25 (Feb 16–20): FlashAttention-2 (Week 15 catch-up)

**Theme**: FA-2 loop order, warp partition, Nsight vs FA-1 and SDPA.

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 16** | Online softmax recap (`m`, $\ell$). | FlashAttention-2 (Dao 2023). | **CUDA**: FA-2 loop order on Week 15 kernel. |
| **Tue Feb 17** | Work/span of tiled GEMM. | Warp partition along sequence. | **CUDA**: Reduce inter-warp sync; unit-test vs PyTorch. |
| **Wed Feb 18** | Numerical stability of online softmax. | `ncu` metrics: DRAM, achieved TFLOPS. | **CUDA (required)**: Nsight FA-1 vs FA-2 vs SDPA. |
| **Thu Feb 19** | GQA + FA: fewer KV tiles. | Integrate GQA from Week 2/4. | **Python/CUDA**: FA-2 path with `num_kv_heads`. |
| **Fri Feb 20** | — | — | Expose FA-2 via `cpp_extension`. Document speedup table for March paper. |

#### 📋 Daily Action Items & Optional Activities (Week 25)
* **Mon Feb 16**:
  * `[ ]` **Core**: Implement FlashAttention-2 loop inversion (outer loop over $Q$ blocks, inner loop over $K, V$ blocks) to reduce shared memory write traffic.
  * `⭐ Optional / Stretch`: Derive the exact register footprint comparison between FlashAttention-1 and FlashAttention-2.
* **Tue Feb 17**:
  * `[ ]` **Core**: Implement sequence-level warp partitioning inside thread blocks; eliminate inter-warp synchronization barriers during forward pass.
  * `⭐ Optional / Stretch`: Verify numerical equivalence against PyTorch `scaled_dot_product_attention` across sequence lengths $L \in [512, 16384]$.
* **Wed Feb 18**:
  * `[ ]` **Core**: Profile FA-1 vs FA-2 vs PyTorch SDPA in Nsight Compute (`ncu`); measure achieved TFLOPS and DRAM bandwidth saturation.
  * `⭐ Optional / Stretch`: Calculate tensor core compute efficiency percentage (% of theoretical FP16 peak).
* **Thu Feb 19**:
  * `[ ]` **Core**: Implement Grouped-Query Attention (GQA) support in FA-2 kernel (`num_heads_q != num_heads_kv`); broadcast $K, V$ heads to query groups in SRAM.
  * `⭐ Optional / Stretch`: Benchmark latency speedup of GQA ($G=8$) vs MHA ($G=1$) at batch size 32.
* **Fri Feb 20**:
  * `[ ]` **Core**: Build production PyTorch C++ extension bindings for FA-2; generate speedup curves for Month 7 publication paper.
  * `⭐ Optional / Stretch`: Implement causal masking without branching by computing diagonal tile intersections.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** implement backward gradient kernels for FA-2—forward inference execution is the complete target.
* ❌ **Do NOT** hand-tune PTX for specific Hopper (SM90) wgmma instructions—standard FP16/BF16 shared-memory tiling provides massive speedup portably.
* ❌ **Do NOT** spend days micro-optimizing head dimensions beyond $d \in \{64, 128\}$.

> **📝 Essay 25 (Sat Feb 21)**: *"Warp Partitioning and Register Rescaling: Implementing FlashAttention-2 with Grouped-Query Attention"*

---

### Week 26 (Feb 23–27): PagedAttention polish on naive KV

**Theme**: Week 4 naive KV is the baseline; this week **pages** it (Week 19 may already have a first BlockTable — finish correctness + GQA).

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 23** | Virtual memory recap (CS:APP Ch 9). | vLLM PagedAttention §4. | **CUDA**: BlockTable + paged K/V vs naive concat (A/B latency + memory). |
| **Tue Feb 24** | Fragmentation vs bitwidth (TurboQuant). | TurboQuant KV blog. | Design note: paging ≠ quantizing; optional QJL sketch. |
| **Wed Feb 25** | — | cuVS / serving APIs. | Hybrid CPU↔GPU fallback polish. |
| **Thu Feb 26** | — | Batch size crossover. | Plot $B=1..1000$ with **paged** KV. |
| **Fri Feb 27** | Month 6 paper remaining figures. | — | Freeze ACORN/tombstone paper if not done Feb 28. |

#### 📋 Daily Action Items & Optional Activities (Week 26)
* **Mon Feb 23**:
  * `[ ]` **Core**: Benchmark Paged KV cache vs naive contiguous KV buffer under continuous autoregressive token generation; measure physical VRAM savings.
  * `⭐ Optional / Stretch`: Implement copy-on-write page table semantics for parallel beam search decoding.
* **Tue Feb 24**:
  * `[ ]` **Core**: Document technical architecture trade-off: memory paging (vLLM) vs extreme coordinate quantization (TurboQuant).
  * `⭐ Optional / Stretch`: Implement 3-bit PolarQuant dequantization on-the-fly in PagedAttention SRAM staging.
* **Wed Feb 25**:
  * `[ ]` **Core**: Polish heterogeneous CPU↔GPU memory fallback: dynamically migrate cold KV pages to host RAM over PCIe.
  * `⭐ Optional / Stretch`: Measure page eviction latency and throughput over PCIe 4.0/5.0 bus.
* **Thu Feb 26**:
  * `[ ]` **Core**: Benchmark serving throughput across concurrency levels $B \in [1, 1000]$; plot tokens/second vs concurrent sequence count.
  * `⭐ Optional / Stretch`: Profile memory manager overhead (block allocation and free list synchronization) under high request churn.
* **Fri Feb 27**:
  * `[ ]` **Core**: Finalize Month 6 paper figures and experimental artifacts; freeze publication document.
  * `⭐ Optional / Stretch`: Prepare automated benchmark reproduction scripts with Docker / shell runner.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** build a distributed speculative decoding engine—focus on single-node paged KV memory savings.
* ❌ **Do NOT** spend time writing complex web UI dashboards for LLM serving—CLI output with tokens/sec is optimal.
* ❌ **Do NOT** implement complex prefix caching trees—simple LRU page table eviction covers all requirements.

> **📝 Essay 26 (Sat Feb 28)**: *"Memory Fragmentation Under Autoregressive Generation: A/B Profiling Naive vs Paged KV Caches"*  
> **🚀 Month 6 PUBLISH (Sun Feb 28)** if not already.

---

### Week 27 (Mar 2–6): Multi-GPU + ColPali ingest

**Theme**: NCCL search scaling; finish vision–text index.

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Mar 2** | AllReduce vs AllGather cost. | NCCL ring algorithms. | **secan**: Multi-GPU IVF load-balance polish (Week 20). |
| **Tue Mar 3** | — | NVLink vs PCIe. | Scaling efficiency 1/2/4 GPU (or 1 GPU simulated shards). |
| **Wed Mar 4** | Contrastive InfoNCE recap. | ColPali paper. | Ingest CLIP-projected patches into `MultiVectorIndex`. |
| **Thu Mar 5** | — | GPU MaxSim CUTLASS. | Text query → visual page search E2E. |
| **Fri Mar 6** | — | — | Month 7 paper figures: GPU QPS + ColPali demo. |

#### 📋 Daily Action Items & Optional Activities (Week 27)
* **Mon Mar 2**:
  * `[ ]` **Core**: Polish multi-GPU IVF load balancing: implement dynamic work-stealing for query batches across GPU streams.
  * `⭐ Optional / Stretch`: Derive theoretical communication lower bounds for AllGather vs ReduceScatter in top-$k$ merging.
* **Tue Mar 3**:
  * `[ ]` **Core**: Measure scaling efficiency curve across 1, 2, and 4 GPU configurations (or multi-stream partition simulation).
  * `⭐ Optional / Stretch`: Profile GPU-to-GPU peer memory copy bandwidth vs host-mediated staging.
* **Wed Mar 4**:
  * `[ ]` **Core**: Ingest CLIP/SigLIP visual patch embeddings into `MultiVectorIndex`; structure multi-vector storage with token centroid routing.
  * `⭐ Optional / Stretch`: Measure token compression ratio using visual patch pooling (e.g. 1024 patches $\to$ 256 tokens).
* **Thu Mar 5**:
  * `[ ]` **Core**: Run end-to-end multimodal search: natural language query $\to$ GPU CUTLASS MaxSim $\to$ retrieved PDF document pages.
  * `⭐ Optional / Stretch`: Build an interactive terminal visualizer rendering ASCII bounding boxes or page previews for top-5 results.
* **Fri Mar 6**:
  * `[ ]` **Core**: Generate Month 7 paper benchmark plots: Multi-GPU scaling curves, FlashAttention-2 speedups, and ColPali visual retrieval metrics.
  * `⭐ Optional / Stretch`: Package reproducible Python demonstration notebook for the ColPali + `secan` engine.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** train full multimodal vision-language models from scratch—use pre-trained ColPali weights to generate document embeddings.
* ❌ **Do NOT** spend days on custom PDF rendering libraries—use PyMuPDF (`fitz`) to extract page images.
* ❌ **Do NOT** build complex multi-host network protocols—focus on single-node multi-GPU NCCL.

> **📝 Essay 27 (Sat Mar 7)**: *"Distributed Multi-GPU Partitioning and Visual Late Interaction: Scaling Document Page Retrieval"*

---

### Week 28 (Mar 9–13): 7-Month Release

**Theme**: `v2.0` — VS spine + GPU specialization + slow-path DL.

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Mar 9** | 7-month geometric thread recap. | API/docs pass. | Finish CLI + Doxygen. |
| **Tue Mar 10** | — | `ann-benchmarks`. | Full CPU+GPU benchmark matrix. |
| **Wed Mar 11** | — | Examples. | Five examples including dense InfoNCE search + GPU batch. |
| **Thu Mar 12** | — | README. | **Publish Month 7 paper.** Tag `v2.0-complete`. |
| **Fri Mar 13** | Rest / interview packet. | — | Portfolio: 7 papers + `secan` Pareto plots. |

#### 📋 Daily Action Items & Optional Activities (Week 28)
* **Mon Mar 9**:
  * `[ ]` **Core**: Complete unified CLI interface (`secan`) and generate full Doxygen API reference documentation.
  * `⭐ Optional / Stretch`: Write a comprehensive architectural design paper summarizing the 7-month engineering journey.
* **Tue Mar 10**:
  * `[ ]` **Core**: Execute full `ann-benchmarks` protocol across all implemented index types: Flat, IVF, SQ8, PQ, FastScan, HNSW, IVFPQ, HNSWSQ, GPU-IVF, DiskANN.
  * `⭐ Optional / Stretch`: Plot combined CPU/GPU Pareto frontier curves (Recall@10 vs QPS) comparing `secan` directly against `Faiss` and `hnswlib`.
* **Wed Mar 11**:
  * `[ ]` **Core**: Build 5 standalone C++ and Python example programs (exact scan, HNSW text search, ColBERT late interaction, GPU IVF batching, hybrid BM25+ANN).
  * `⭐ Optional / Stretch`: Add a zero-dependency quickstart script that clones, builds, downloads SIFT1M, and benchmarks in under 60 seconds.
* **Thu Mar 12**:
  * `[ ]` **Core**: Finalize root `README.md` with complete benchmark tables; publish Month 7 research paper; git tag `v2.0-complete`.
  * `⭐ Optional / Stretch`: Prepare public release announcement and publish technical blog posts summarizing key architectural discoveries.
* **Fri Mar 13**:
  * `[ ]` **Core**: Compile professional engineering portfolio packet: 7 conference-grade research papers, 28 technical essays, and `secan` repository release.
  * `⭐ Optional / Stretch`: Celebrate completing the 28-week vector search engine & AI systems specialization!

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** try to add brand new algorithmic features in Week 28—this is strictly a stabilization, benchmarking, documentation, and release week.
* ❌ **Do NOT** over-complicate documentation styling—clean Markdown and standard Doxygen HTML are standard.
* ❌ **Do NOT** doubt your progress—you have built a world-class, conference-grade vector search engine and AI systems foundation from first principles.

> **📝 Essay 28 (Sat Mar 14)**: *"Seven Months from First Principles: Vector Spaces, Modern SIMD/GPU Architectures, and the `v2.0` Engine"*  
> **🚀 Month 7 research PUBLISH (Thu Mar 12)**: `research/2027-03-gpu-serving/paper.md`

---

