# Hard landings & ledgers

> Required VS / DL / deferred landings. Week tables: [`weeks/`](weeks/). Curriculum index: [`README.md`](README.md).

## Deferred-work ledger (slimmed → hard landing)

Nothing slimmed is optional. Every row is **required** on the landing week.

| Slimmed from | What was cut | **Hard landing (required)** | Why there |
|:---|:---|:---|:---|
| **Week 8** | HNSW bounded flat heap + bitset visited | **Week 12 Wed** | Before composed-index Pareto |
| **Week 10** | BM25 + Block-Max WAND + **RRF** | **Week 16 Fri** | Hybrid IR; not only linear $\alpha$ |
| **Week 11** | DiskANN `io_uring` + **Vamana prune** | **Week 16 Thu** | Graph construction, not only SSD fetch |
| **Week 15** | FlashAttention-2 | **Week 25** | GPU block |
| **Week 7→10** | RaBitQ (after QR) | **Week 10 Thu** | Already required |
| **Week 8→12** | Whitening / query-side PCA | **Week 12 Mon** | After SVD |
| *(frontier)* | ACORN + tombstones + NUMA + **pre/post/range** | **Week 22** | On-call filters |

## VS composition landings (the specialty)

REST out of scope. Cluster shard/replica = stretch only.

| Need | Lands (required) |
|:---|:---|
| **IP/MIPS + spherical k-means IVF** + list-size histogram / rebalance | **Week 4 Thu–Fri** |
| **Asymmetric PQ/BQ** (FP32 query vs quantized db) + **OPQ / residual PQ** | **Week 6 Fri + Week 7 Fri** |
| **768-D text Recall@10 vs QPS** (golden pre-staged `.fvecs` + DL model parity) | **Week 8 Fri** |
| **Batch HNSW / graph build** | **Week 9 Mon–Tue** |
| **MUVERA FDE** (asymmetric) → IP MIPS → MaxSim re-rank vs PLAID | **Week 10 Mon–Wed** |
| **TurboQuant 1@k** vs RaBitQ/PQ (GloVe or 768-D) | **Week 10 Fri** |
| **`IVFPQIndex` + `HNSWSQIndex`**; Pareto vs Faiss/hnswlib on **SIFT + 768-D** | **Week 12 Thu–Fri** |
| **ONNX → ORT** dense bi-encoder → `.fvecs` → `secan` (PyTorch parity) | **Week 12 Sat** |
| **Vamana prune** + compressed RAM + `io_uring` raw (**Deep10M** core; Deep1B NVMe tier) | **Week 16 Thu** |
| **RRF** + linear $\alpha$ (SPLADE stretch) | **Week 16 Fri** |
| **Pre- vs post-filter vs ACORN**; **range**; selectivity vs recall | **Week 22 Mon + Fri** |
| BEIR / MS MARCO **slice** (dense + ColBERT + **MUVERA**) | **Month 3 research Sunday** |
| REST API | **Skip** |

## DL weekend landings (Sat 14:00–18:00 only)

| Weekend after | DL work |
|:---|:---|
| **W1 Sat Sep 6** | SDPA + causal mask (`uv init transformers-pytorch`) |
| **W2 Sat Sep 13** | MHA + **GQA**; Pre-LN vs Post-LN |
| **W3 Sat Sep 20** | **🔗 Micrograd autograd engine** (~150 lines) + Pre-LN encoder + FFN + manual `backward()` for `Linear` |
| **W4 Sat Sep 27** | **RoPE + SwiGLU + CausalLM + CE + naive KV** + **SGD from scratch** (momentum, verify vs `torch.optim.SGD`) |
| **W5 Sat Oct 4** | ViT patch embed + `[CLS]` |
| **W6 Sat Oct 11** | BERT + **InfoNCE** + **in-batch negatives** + **hard negative mining** (BM25 top-100); **AdamW from scratch**; export 768-D `.fvecs` for Week 8 Fri |
| **W7 Sat Oct 18** | MRL tiny-corpus |
| **W8 Sat Oct 25** | *Month 2 publish* — no extra DL |
| **W9 Sat Nov 1** | ColBERT + MaxSim + tiny Margin MSE + **knowledge distillation** (cross-encoder → bi-encoder) |
| **W12 Sat Nov 22** | **ONNX required**: InfoNCE bi-encoder → ONNX → **ORT**; PyTorch parity; emit 768-D `.fvecs` → `secan` |
| **W15 Sat Dec 13** | Online softmax (FA-1 math) |
| **W21 Sat Jan 24** | CLIP projector + ColPali head |
| **W23 Sat Feb 7** | Stretch: re-run same ORT graph on ARM host (with NEON week) |
| Other Saturdays | Research / overflow only |

---

---

---
## ⚔️ Dual-Use Military & Tactical Mission Mapping (DL Saturdays)

Every Saturday Deep Learning implementation is a dual-use weapon system component:

| DL Weekend | Model / Architecture | Tactical Defense & Military Edge Application |
|:---|:---|:---|
| **W1 Sat Sep 6** | SDPA + Causal Masking | **Phased-Array Antenna Signal Beamforming**: Multi-channel temporal attention over phased RF pulse streams. |
| **W2 Sat Sep 13** | MHA + GQA (Grouped-Query Attention) | **SWaP-Constrained Sensor Fusion**: Low-memory multi-head attention on edge airborne processors. |
| **W3 Sat Sep 20** | Micrograd Autograd from Scratch | **Deterministic Gradient Evaluation**: Zero-dependency backpropagation for embedded missile guidance physics. |
| **W4 Sat Sep 27** | RoPE + SwiGLU + CausalLM | **Rotary Coordinate Tracking**: Relative spatial orientation encoding for dynamic drone swarm formations. |
| **W5 Sat Oct 4** | Vision Transformer (ViT) from Scratch | **Autonomous Optical / FLIR Missile Seekers**: Real-time target recognition and tracking in GPS-denied environments. |
| **W6 Sat Oct 11** | BERT + InfoNCE Contrastive Loss | **Multimodal SIGINT-to-GEOINT Cross-Referencing**: Aligning intercepted RF radar pulse signatures with optical satellite imagery. |
| **W7 Sat Oct 18** | MRL (Matryoshka Representation Learning) | **Adaptive Bandwidth Transmission**: Transmitting coarse 64-D vectors over jammed Link-16 RF, expanding to 768-D in line-of-sight. |
| **W9 Sat Nov 1** | ColBERT + MaxSim Late Interaction | **Real-Time Electronic Order of Battle (EOB)**: Searching millions of complex, multi-modal radar emitter signatures. |
| **W12 Sat Nov 22** | ONNX → ORT Engine Deployment | **Air-Gapped Embedded Avionics Deployment**: Zero-Python standalone C++ inference on edge flight controllers. |
| **W15 Sat Dec 13** | Online Softmax & FlashAttention-1 | **High-Frequency Radar Chirp & Sonar Processing**: Processing raw long-duration temporal sequences ($>32	ext{K}$) without VRAM blowup. |
| **W21 Sat Jan 24** | ColPali / Visual Late Interaction | **Automated Aerial Reconnaissance Exploitation**: Searching wide-area synthetic aperture radar (SAR) imagery for camouflaged targets. |
| **W25 Sat Feb 21** | FlashAttention-2 with GQA | **Onboard Tactical Swarm Autonomy (DARPA ACE / CCA)**: Onboard mission reasoning models inside the 32GB memory of a Jetson Orin AGX. |
