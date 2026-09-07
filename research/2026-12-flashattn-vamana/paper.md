# Scaling Frontiers: In-VRAM GPU IVF vs. Asynchronous NVMe DiskANN Under Concurrent Query Pressure

| Metadata | Specification |
|:---|:---|
| **Month** | 4 — December 2026 |
| **Status** | Empirical Benchmark Report |
| **Domain** | Out-of-Core Graph Algorithms, Kernel-Bypass Direct I/O, GPU Acceleration |

---

## 1. Executive Abstract & Falsifiable Question


**Core Falsifiable Question**:
> *At what dataset scale ($10	ext{M} 	o 100	ext{M}$ vectors) does out-of-core NVMe DiskANN using asynchronous Linux `io_uring` kernel-bypass direct I/O surpass in-VRAM GPU IVF on a Cost-per-QPS and Watt-per-Query basis while sustaining $>95\%$ Recall@10 under concurrent multi-client query pressure?*

---

## 2. Systems & Mathematical Formulation

1. **Vamana Graph Geometric Spanner Property**:
   * Candidate neighbor $c$ is kept if and only if:
     $$lpha \cdot d(r, c) > d(p, c) \quad orall r \in N(p)$$
   * Guarantees an $lpha$-spanner network with diameter $\mathcal{O}(\log N)$, preventing local search traps during disk beam traversal.
2. **NVMe Direct I/O via `io_uring`**:
   * Uses `IORING_SETUP_SQPOLL` to execute kernel-bypass asynchronous 4KB block reads directly from solid-state NVMe drives.
   * Eliminates Linux page cache overhead, memory double-buffering, and context-switch stalls ($T_{	ext{read}} pprox 8	ext{–}15\ \mu	ext{s}$).
3. **Cost-Latency-Energy Frontier**:
   $$	ext{Efficiency} = rac{	ext{QPS}}{	ext{Hardware Cost (\$)}} \quad 	ext{and} \quad 	ext{Energy} = rac{	ext{Joules}}{	ext{Query}}$$

---

## 3. Experimental Matrix
* **Scale**: $10	ext{M}$ vectors (SIFT10M / DEEP10M) up to $100	ext{M}$ vectors.
* **Storage**: PCIe Gen4 NVMe SSD vs NVIDIA GPU HBM.
* **Concurrent Concurrency**: 1 to 64 parallel query worker threads.

---

## 4. Reproducibility
```bash
./build/benchmarks/bench_diskann_iouring --index_path=/mnt/nvme/diskann_10m.index --threads=32
```
