# Month 5 — Jan (Weeks 17–20)

> Part of the [28-week curriculum](../README.md). Research: [`research/`](../../research/README.md).

| | |
|:---|:---|
| [← Month 4 — Dec](month-04-dec.md) | [Month 6 — Feb →](month-06-feb.md) |

---

# BLOCK II: GPU SPECIALIZATION (Weeks 17–28 / Jan–Mar 2027)

Weekdays remain **`secan`/CUDA**. DL stays **Saturday afternoon**. Cluster shard/replica beyond NCCL = stretch. **No REST.**

---

# 📅 MONTH 5: Mathematical Statistics, Limit Theorems, GPU Graphs & Multi-GPU (Jan 2027)

> **🔬 Empirical Systems & Benchmarking Focus**: *The Online Max Reduction Invariant & In-SRAM Accumulation Mechanics* · folder `research/2027-01-cagra-warp-search/`

---


### 📚 Master Reference Textbooks (Month 5)
* **Statistical Inference**: George Casella & Roger L. Berger, *Statistical Inference* (2nd ed, Duxbury 2001) — Ch 6 (Data Reduction / Sufficiency), Ch 7 (Point Estimation, Cramér-Rao Lower Bound), Ch 8 (Hypothesis Testing / Likelihood Ratio Tests), Ch 10 (Asymptotic Evaluations).
* **GPU Architecture & Programming**: David B. Kirk & Wen-mei W. Hwu, *Programming Massively Parallel Processors* (4th ed) — Ch 5–7 (Memory Coalescing, Bank Conflicts, Warp Divergence, Parallel Reductions).

---

### Week 17 (Sat Dec 26 – Fri Jan 1): Limit Theorems, LLN, CLT, Inequalities & CAGRA GPU Graphs

**Theme**: Laws of Large Numbers, Central Limit Theorem, probability inequalities, and GPU CAGRA graph traversal.

* **Pure Probability (Blitzstein & Hwang Ch 10)**:
  * Probability Inequalities: Markov's Inequality $P(X \geq a) \leq \frac{\mathbb{E}[X]}{a}$, Chebyshev's Inequality $P(|X - \mu| \geq k\sigma) \leq \frac{1}{k^2}$, Cauchy-Schwarz inequality for random variables $|\mathbb{E}[XY]|^2 \leq \mathbb{E}[X^2]\mathbb{E}[Y^2]$, Chernoff bounds.
  * **Weak and Strong Law of Large Numbers (WLLN & SLLN)**: Convergence in probability vs almost sure convergence. Sample mean $\bar{X}_n \to \mu$.
  * **The Central Limit Theorem (CLT)**: Rigorous proof via Moment Generating Functions that $\frac{\sum X_i - n\mu}{\sigma \sqrt{n}} \xrightarrow{d} \mathcal{N}(0, 1)$.
* **C++ Engine (`secan`)**: GPU HNSW/CAGRA-style graph traversal, warp-cooperative neighbor evaluation, visited-set bitmasks with `__ballot_sync`.

| Day | Pure Probability (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 22** | **PROB §10.1**: Probability inequalities: Markov's and Chebyshev's inequalities proofs and applications in tail bounds. | Research paper: *"CAGRA: Highly Parallel Graph Construction and ANN Search for GPUs"* (NVIDIA 2024) §1–4. | **secan**: Design GPU graph layout: store HNSW graph adjacency in GPU memory as a fixed-degree CSR array with padding. |
| **Tue Dec 23** | **PROB §10.2**: Chernoff bounds: exponential moment bounds $P(X \geq a) \leq \min_{t > 0} \frac{M_X(t)}{e^{ta}}$. Tail bounds for sums of random variables. | CAGRA paper §5–6: Search kernel design, warp-level parallel beam search, avoiding dynamic queues on GPU. | **secan**: Implement **GPU graph search kernel**: each warp processes 1 query. 32 threads in warp evaluate 32 candidate neighbors in parallel. |
| **Wed Dec 24** | **PROB §10.3**: The Law of Large Numbers (LLN): Weak Law of Large Numbers proof via Chebyshev; Strong Law of Large Numbers (Borel-Cantelli lemmas). | **CUDA-GUIDE Warp Primitives**: `__ballot_sync`, `__any_sync`, warp-local bitfield operations. | **secan**: Implement warp-level visited set using `__ballot_sync` bitfields. Implement warp-level top-$k$ beam with shuffle min-reduction. |
| **Thu Dec 25** | **PROB §10.4**: The Central Limit Theorem (CLT): Step-by-step rigorous proof using Taylor expansion of MGFs. | **PMPP Ch 9**: Parallel Prefix Sum (Scan) for compacting candidate neighbor lists on GPU. | **secan**: Implement multi-query parallel graph search: launch grid of warps. Benchmark throughput vs CPU HNSW. |
| **Fri Dec 26** | **PROB §10.5**: Applications of CLT in statistical error estimation and confidence intervals. | Profile GPU graph search with `ncu`: measure compute-to-memory stall ratio. | **secan**: Optimize GPU graph search: add shared memory caching for frequently visited upper-layer hub nodes. |

#### 📋 Daily Action Items & Optional Activities (Week 17)
* **Mon Dec 22**:
  * `[ ]` **Core**: Design GPU graph layout: store HNSW graph adjacency in GPU memory as a fixed-degree CSR array with padding.
  * `⭐ Optional / Stretch`: Derive Chernoff bounds on the probability of graph search getting trapped in local minima.
* **Tue Dec 23**:
  * `[ ]` **Core**: Implement GPU graph search kernel: 1 warp per query; 32 threads evaluate 32 candidate neighbors in parallel.
  * `⭐ Optional / Stretch`: Profile warp divergence during neighbor list filtering with Nsight Compute (`ncu`).
* **Wed Dec 24**:
  * `[ ]` **Core**: Implement warp-level visited set using `__ballot_sync` bitfields; implement warp-level top-$k$ beam with shuffle min-reduction.
  * `⭐ Optional / Stretch`: Implement hash-based visited table in shared memory for graphs with degree $M > 64$.
* **Thu Dec 25**:
  * `[ ]` **Core**: Launch multi-query parallel graph search grid; benchmark QPS vs CPU HNSW implementation.
  * `⭐ Optional / Stretch`: Measure the impact of thread block occupancy on memory latency hiding during random graph pointer chasing.
* **Fri Dec 26**:
  * `[ ]` **Core**: Add shared memory caching for frequently visited upper-layer hub nodes to eliminate global memory roundtrips.
  * `⭐ Optional / Stretch`: Compute graph degree centrality to identify top-64 hub nodes for permanent SRAM staging.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** implement dynamic-degree variable-length CSR arrays on GPU—pad neighbor lists to fixed max degree $M$ for uniform warp loads.
* ❌ **Do NOT** maintain per-thread dynamic candidate queues in global memory—warp-cooperative bitfield visited masks eliminate queue allocation.
* ❌ **Do NOT** write measure-theoretic probability proofs for SLLN—grasp the Chebyshev proof for WLLN and move on.

> **📝 Essay 17 (Sat Dec 27)**: *"Warp-Scale Graph Traversal: Overcoming Random Memory Access Bottlenecks in GPU CAGRA"*  
> **🚀 Month 4 Builder Milestone (Sun Dec 27)**: End-to-end FlashAttention & Vamana GPU kernel benchmark verification.

---

### Week 18 (Sat Jan 2 – Fri Jan 8): Markov Chains, Transition Matrices & GPU FastScan

**Theme**: Discrete-time Markov chains, stationary distributions, and GPU shared-memory FastScan.

* **Pure Probability (Blitzstein & Hwang Ch 11–12)**:
  * Discrete-Time Markov Chains (DTMC): State space, Markov property $P(X_{n+1}=j | X_n=i, \dots) = P(X_{n+1}=j | X_n=i)$, Transition Probability Matrix $P$.
  * $n$-step transitions: Chapman-Kolmogorov equations, $P^{(n)} = P^n$.
  * Classification of states: Recurrent vs Transient, Absorbing states, Periodicity, Irreducibility.
  * **Stationary Distributions**: $\boldsymbol{\pi} P = \boldsymbol{\pi}$ with $\sum \pi_i = 1$. Existence and uniqueness theorems (Perron-Frobenius theorem connection). Random walks on graphs.
* **C++ Engine (`secan`)**: GPU PQ ADC kernel (LUT in shared memory), GPU FastScan using warp shuffles (`__shfl_sync`), GPU IVF-PQ combined index.

| Day | Pure Probability (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 29** | **PROB §11.1–11.2**: Markov chains definition, transition probability matrix $P$, state transition diagrams, Chapman-Kolmogorov equations. | Faiss GPU PQ documentation: storing query lookup tables in GPU shared memory. | **secan**: Implement GPU PQ ADC kernel: upload query LUT to shared memory. Threads compute PQ distances via shared-memory lookups. |
| **Tue Dec 30** | **PROB §11.3**: Classification of states: irreducibility, periodicity, recurrence and transience. Absorbing Markov chains and fundamental matrix. | **CUDA-GUIDE Shared Memory**: Bank conflicts, padding strategies, broadcast mechanisms. | **secan**: Optimize shared-memory LUT layout: apply padding to ensure conflict-free broadcast reads during distance accumulation. |
| **Wed Dec 31** | **PROB §11.4**: Stationary distributions: solving $\boldsymbol{\pi} P = \boldsymbol{\pi}$ as a left-eigenvector problem with eigenvalue $\lambda = 1$. | Research: GPU FastScan architecture using warp-level registers. | **secan**: Implement **GPU 4-bit FastScan**: store 16 centroid distances in warp registers. Execute lookups via `__shfl_sync(mask, dist, code)`. |
| **Thu Jan 1** | **PROB §11.5–11.6**: Random walks on graphs: proving that $\pi_i = \frac{d_i}{2|E|}$ is the stationary distribution on an undirected graph with degree $d_i$. | **PMPP Ch 18**: Multi-GPU concepts, CUDA IPC, peer-to-peer memory access. | **secan**: Implement **GPU IVF-PQ**: combine GPU coarse cell routing with GPU FastScan distance inside cells. |
| **Fri Jan 2** | **PROB §12.1–12.3**: Markov Chain Monte Carlo (MCMC): Metropolis-Hastings algorithm theory and proof of detailed balance. | Review all GPU quantization kernels. | **secan**: Benchmark GPU-FP32 vs GPU-FP16 vs GPU-SQ8 vs GPU-IVF-PQ vs GPU-FastScan. Create comprehensive comparison table. |

#### 📋 Daily Action Items & Optional Activities (Week 18)
* **Mon Dec 29**:
  * `[ ]` **Core**: Implement GPU PQ ADC kernel staging query centroid lookup tables ($M \times 256$ floats) in shared memory.
  * `⭐ Optional / Stretch`: Derive the exact transition probability matrix of random walk beam search on a small $k$-regular graph.
* **Tue Dec 30**:
  * `[ ]` **Core**: Optimize shared-memory LUT layout with stride padding; verify 0 shared-memory bank conflicts in `ncu`.
  * `⭐ Optional / Stretch`: Benchmark shared memory broadcast efficiency when all 32 warp threads access the identical centroid entry.
* **Wed Dec 31**:
  * `[ ]` **Core**: Implement GPU 4-bit FastScan storing 16 centroid distances across 16 warp registers; execute table lookups via `__shfl_sync(mask, dist, code)`.
  * `⭐ Optional / Stretch`: Measure register pressure and warp occupancy trade-offs in GPU FastScan kernel.
* **Thu Jan 1**:
  * `[ ]` **Core**: Compose GPU IVF-PQ index (GPU coarse quantizer + GPU FastScan kernel inside selected cells).
  * `⭐ Optional / Stretch`: Implement asynchronous batch cell scanning using multiple CUDA streams.
* **Fri Jan 2**:
  * `[ ]` **Core**: Benchmark full suite: GPU-FP32 vs GPU-FP16 vs GPU-SQ8 vs GPU-IVF-PQ vs GPU-FastScan; produce comprehensive performance matrix.
  * `⭐ Optional / Stretch`: Compute total memory bandwidth efficiency percentage against theoretical GPU VRAM bandwidth limit.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** implement 8-bit FastScan—4-bit FastScan fits 16 centroids directly in 16 warp registers for zero-shared-memory execution.
* ❌ **Do NOT** spend hours proving stationary distributions for continuous-state Markov processes—focus on finite discrete-state transition matrices.
* ❌ **Do NOT** tune codebook centroids on GPU—train codebooks offline on CPU/NumPy and upload final centroids to device memory.

> **📝 Essay 18 (Sat Jan 3)**: *"Markov Chains, Graph Random Walks, and High-Throughput GPU Quantized FastScan"*

---

### Week 19 (Sat Jan 9 – Fri Jan 15): Mathematical Statistics, MLE, PagedAttention & KV Compression

**Theme**: Point estimation, MLE, Fisher Information, PagedAttention (vLLM), and **TurboQuant-style KV quantization** (3-bit, training-free).

* **Mathematical Statistics (Statistical Theory)**:
  * Point Estimation: Estimators $\hat{\theta}(X_1, \dots, X_n)$, Bias $\text{Bias}(\hat{\theta}) = \mathbb{E}[\hat{\theta}] - \theta$, Mean Squared Error $\text{MSE}(\hat{\theta}) = \text{Var}(\hat{\theta}) + \text{Bias}^2$.
  * **Maximum Likelihood Estimation (MLE)**: Likelihood function $L(\theta; \mathbf{x}) = \prod f(x_i; \theta)$, log-likelihood $\ell(\theta)$, score function $S(\theta) = \ell'(\theta)$, solving $\ell'(\hat{\theta}) = 0$.
  * Fisher Information $I(\theta) = \mathbb{E}\left[\left(\frac{\partial}{\partial \theta} \ln f(X; \theta)\right)^2\right] = -\mathbb{E}\left[\frac{\partial^2}{\partial \theta^2} \ln f(X; \theta)\right]$.
  * Cramér-Rao Lower Bound (CRLB): $\text{Var}(\hat{\theta}) \geq \frac{1}{n I(\theta)}$ for unbiased estimators. Efficiency of estimators.
* **Systems / Frontier Reading**: CS:APP Chapter 9 "Virtual Memory" + vLLM PagedAttention + [TurboQuant](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/) KV path (PolarQuant stage + 1-bit QJL residual; unbiased attention-score estimator; ~6× KV memory cut, up to ~8× logits speedup on H100 in blog numbers).
* **C++ Engine (`secan`) & Python**:
  * **Python/CUDA**: Implement `BlockTable` + **PagedAttention** kernel; optional **stretch**: apply PolarQuant/QJL sketch to cached $K$ (or document design only if timeboxed).
  * **secan**: Double-buffered async pinned memory pipeline (`cudaHostAlloc`) overlapping batch search compute with PCIe transfers.

| Day | Mathematical Statistics (90 min) | GPU / vLLM Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 5** | **STATS §1.1–1.3**: Point estimation foundations: Sample mean, sample variance ($s^2$ with $n-1$ denominator for unbiasedness), MSE decomposition. | vLLM Paper §1–3: The KV Cache fragmentation problem in LLMs ($60\%–80\%$ memory wasted on over-allocation). | **Python/CUDA**: Implement `BlockTable` data structure in PyTorch: maps logical sequence tokens to physical GPU memory blocks (block size 16). |
| **Tue Jan 6** | **STATS §2.1–2.3**: Maximum Likelihood Estimation (MLE): Deriving MLE for Gaussian mean/variance, Poisson $\lambda$, and Bernoulli $p$. Invariance property of MLEs. | vLLM Paper §4: PagedAttention kernel design: reading $K, V$ blocks via block lookup table in CUDA. | **CUDA**: Implement **PagedAttention CUDA kernel**: during self-attention, resolve physical $K, V$ block pointers on-the-fly via block table. |
| **Wed Jan 7** | **STATS §2.4–2.5**: Fisher Information: Definition and mathematical equivalence of variance of score vs negative expected Hessian of log-likelihood. | [TurboQuant](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/): KV experiments (LongBench, RULER, needle-in-haystack); PolarQuant + QJL residual as bias killer for attention scores. | **secan**: Build unified `GpuIndex` wrapper class: device memory lifecycle, async transfers, kernel launches, RAII cleanup. |
| **Thu Jan 8** | **STATS §2.6**: Cramér-Rao Lower Bound (CRLB): Step-by-step rigorous proof using Cauchy-Schwarz inequality on the score function. | **PMPP Ch 19**: Heterogeneous CPU+GPU workload partitioning. | **secan**: Implement **CPU↔GPU hybrid fallback**: partition oversized dataset into GPU VRAM (fast) and CPU RAM (AVX2). Merge results. |
| **Fri Jan 9** | **STATS §3.1–3.3**: Hypothesis testing foundations: Null ($H_0$) and alternative ($H_1$) hypotheses, Type I ($\alpha$) and Type II ($\beta$) errors, p-values, Neyman-Pearson Lemma. | Profile PagedAttention vs standard KV cache memory; contrast with TurboQuant bitwidth story (paging ≠ quantizing). | **secan**: Benchmark query batch sizes ($B=1, 10, 100, 1000$). Plot the CPU vs GPU crossover curve. |

#### 📋 Daily Action Items & Optional Activities (Week 19)
* **Mon Jan 5**:
  * `[ ]` **Core**: Implement PyTorch `BlockTable` data structure mapping logical sequence tokens to physical GPU memory pages (block size 16).
  * `⭐ Optional / Stretch`: Simulate KV cache memory fragmentation under random sequence length arrivals (verify $>60\%$ memory savings).
* **Tue Jan 6**:
  * `[ ]` **Core**: Implement PagedAttention CUDA kernel resolving physical $K, V$ block pointers on-the-fly via block table during attention decoding.
  * `⭐ Optional / Stretch`: Add support for variable sequence lengths in a single batched kernel launch.
* **Wed Jan 7**:
  * `[ ]` **Core**: Build unified `GpuIndex` wrapper managing device memory lifecycle, async streams, and RAII cleanup.
  * `⭐ Optional / Stretch`: Design a PolarQuant 3-bit KV compression sketch storing quantized $K$ cache blocks inside the PagedAttention block table.
* **Thu Jan 8**:
  * `[ ]` **Core**: Implement heterogeneous CPU+GPU fallback pipeline: retain hot dataset in GPU VRAM and overflow in host RAM; merge top-$k$ results.
  * `⭐ Optional / Stretch`: Measure end-to-end query latency as a function of GPU VRAM partition fraction (0% to 100%).
* **Fri Jan 9**:
  * `[ ]` **Core**: Benchmark query batch sizes $B \in [1, 1000]$; plot CPU AVX2 vs GPU latency crossover curve.
  * `⭐ Optional / Stretch`: Compute the exact QPS break-even point where GPU throughput justifies PCIe transfer latency overhead.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** implement dynamic memory defragmentation compaction algorithms—block paging naturally eliminates internal and external fragmentation.
* ❌ **Do NOT** build a full LLM serving scheduler with continuous batching—focus strictly on the `BlockTable` address resolution kernel.
* ❌ **Do NOT** solve advanced hypothesis testing Neyman-Pearson lemma optimization problems by hand—understand Type I/II error trade-offs and move on.

> **📝 Essay 19 (Sat Jan 10)**: *"Virtual Memory for Attention: Paged KV Blocks and Extreme PolarQuant 3-Bit Compression"*

---

### Week 20 (Sat Jan 16 – Fri Jan 22): Information Theory, Entropy, KL-Divergence & Multi-GPU NCCL

**Theme**: Information theory, Shannon entropy, Kullback-Leibler divergence, and multi-GPU distributed search with NCCL.

* **Pure Information Theory (Cover & Thomas / MacKay)**:
  * Shannon Entropy: $H(X) = -\sum p(x) \log_2 p(x)$ (axiomatic definition of uncertainty and information content).
  * Joint Entropy $H(X, Y)$ and Conditional Entropy $H(Y|X) = H(X, Y) - H(X)$.
  * **Relative Entropy / Kullback-Leibler (KL) Divergence**: $D_{KL}(P \| Q) = \sum P(x) \log \frac{P(x)}{Q(x)}$. Proof of Gibbs' Inequality: $D_{KL}(P \| Q) \geq 0$ with equality iff $P = Q$.
  * Mutual Information: $I(X; Y) = H(X) - H(X|Y) = D_{KL}(P(X, Y) \| P(X)P(Y))$.
  * Cross-Entropy: $H(P, Q) = H(P) + D_{KL}(P \| Q) = -\sum P(x) \log Q(x)$.
* **C++ Engine (`secan`)**: `MultiGpuIndex` class, dataset sharding across GPUs, NCCL AllGather result aggregation, multi-GPU load balancing.

| Day | Pure Information Theory (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 12** | **INFO §1.1–1.3**: Shannon Entropy: Information content of events $I(x) = -\log_2 p(x)$, entropy $H(X)$, entropy of Bernoulli and discrete uniform distributions. | **CUDA-GUIDE Multi-GPU**: `cudaSetDevice`, peer-to-peer memory access (`cudaDeviceEnablePeerAccess`). | **secan**: Implement dataset sharding: split $N$ vectors into $G$ shards. Upload shard $i$ to GPU $i$. Build `MultiGpuIndex` class. |
| **Tue Jan 13** | **INFO §1.4–1.6**: Joint Entropy $H(X, Y)$, Conditional Entropy $H(Y|X)$, and the Chain Rule for Entropy: $H(X_1, \dots, X_n) = \sum H(X_i | X_{i-1}, \dots, X_1)$. | NCCL Documentation: `ncclAllGather`, `ncclAllReduce`, ring-based collective algorithms. | **secan**: Implement multi-GPU brute-force search: each GPU searches local shard; use NCCL AllGather to merge per-GPU top-$k$ heaps. |
| **Wed Jan 14** | **INFO §2.1–2.3**: Relative Entropy (KL Divergence) $D_{KL}(P \| Q)$. Rigorous proof that $D_{KL} \geq 0$ via Jensen's Inequality on convex functions. | Faiss multi-GPU implementation: replicated coarse quantizer with sharded inverted lists. | **secan**: Implement **multi-GPU IVF**: replicate coarse centroids on all GPUs; shard inverted lists across GPUs. Route queries via NCCL. |
| **Thu Jan 15** | **INFO §2.4–2.6**: Mutual Information $I(X; Y)$: properties, symmetry $I(X; Y) = I(Y; X)$, connection to KL divergence between joint and product marginals. | NVLink vs PCIe inter-GPU bandwidth analysis. | **secan**: Implement dynamic load balancing: redistribute heavy IVF cells across GPUs to prevent stragglers during multi-probe search. |
| **Fri Jan 16** | **INFO §3.1–3.3**: Cross-Entropy $H(P, Q) = -\sum P(x) \log Q(x)$. Mathematical proof that minimizing Cross-Entropy is equivalent to minimizing KL Divergence to target distribution. | Measure multi-GPU scaling efficiency across 1, 2, and 4 GPUs on synthetic billion-scale data. | **secan**: Benchmark multi-GPU search on SIFT1M and large synthetic datasets. Measure scaling efficiency and communication overhead. |

#### 📋 Daily Action Items & Optional Activities (Week 20)
* **Mon Jan 12**:
  * `[ ]` **Core**: Implement dataset sharding across $G$ GPUs; build `MultiGpuIndex` managing per-device buffers with peer-to-peer access enabled.
  * `⭐ Optional / Stretch`: Derive the maximum Shannon entropy of quantized embedding codes under uniform vs Gaussian coordinate distributions.
* **Tue Jan 13**:
  * `[ ]` **Core**: Implement multi-GPU parallel scan merging per-GPU top-$k$ candidate heaps using `ncclAllGather`.
  * `⭐ Optional / Stretch`: Benchmark NCCL ring-based collective transfer latency over NVLink vs PCIe bus.
* **Wed Jan 14**:
  * `[ ]` **Core**: Implement multi-GPU IVF: replicate coarse centroids across all devices; distribute inverted lists across GPUs.
  * `⭐ Optional / Stretch`: Measure multi-GPU speedup over single GPU on a 10M vector synthetic dataset.
* **Thu Jan 15**:
  * `[ ]` **Core**: Implement dynamic cell redistribution to eliminate GPU load imbalance under skewed query workloads.
  * `⭐ Optional / Stretch`: Profile GPU execution timeline in Nsight Systems (`nsys`) to identify inter-GPU communication bubbles.
* **Fri Jan 16**:
  * `[ ]` **Core**: Run multi-GPU scalability benchmark suite; compute parallel scaling efficiency percentage across GPUs.
  * `⭐ Optional / Stretch`: Test multi-GPU fault tolerance by simulating device dropout and dynamic shard re-routing.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** implement multi-node distributed TCP network clustering—NCCL multi-GPU on a single multi-GPU host is the complete specialization target.
* ❌ **Do NOT** implement complex 2D tensor parallelism—data sharding with top-$k$ heap gathering (`ncclAllGather`) is the standard for vector search.
* ❌ **Do NOT** worry if you only have 1 GPU locally—NCCL supports single-process multi-stream GPU shard simulation.

> **📝 Essay 20 (Sat Jan 17)**: *"Information Theory and Ring Collectives: Shannon Entropy, KL-Divergence, and Multi-GPU NCCL Search"*

---

---
