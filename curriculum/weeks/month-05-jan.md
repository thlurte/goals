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

> **🔬 Monthly research**: *Paging vs Quantizing Memory: PagedAttention and TurboQuant as Complementary KV Levers* → publish **Sun Jan 31** · folder `research/2027-01-paging-vs-quantizing-kv/`

---

### Week 17 (Dec 22–26): Limit Theorems, LLN, CLT, Inequalities & CAGRA GPU Graphs

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

> **📝 Essay 17 (Sat Dec 27)**: *"CAGRA and GPU Graph Traversal: Overcoming Random Memory Access at Warp Scale"*  
> **🚀 Month 4 research PUBLISH (Sun Dec 27)**: freeze `research/2026-12-three-paths-spine/paper.md` + public post.

---

### Week 18 (Dec 29 – Jan 2): Markov Chains, Transition Matrices & GPU FastScan

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

> **📝 Essay 18 (Sat Jan 3)**: *"Markov Chains, Graph Random Walks, and Warp-Shuffle GPU FastScan"*

---

### Week 19 (Jan 5–9): Mathematical Statistics, MLE, PagedAttention & KV Compression

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

> **📝 Essay 19 (Sat Jan 10)**: *"PagedAttention Meets TurboQuant: Virtual Memory for KV Blocks and Extreme Bit Compression"*

---

### Week 20 (Jan 12–16): Information Theory, Entropy, KL-Divergence & Multi-GPU NCCL

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

> **📝 Essay 20 (Sat Jan 17)**: *"Shannon Entropy, Kullback-Leibler Divergence, and Distributed Multi-GPU Search"*

---
