# Streaming Late Interaction: Evaluating PLAID Centroid Inverted Lists vs MUVERA Fixed-Dimensional Encodings in Dynamic LSM Vector Storage

| Metadata | Specification |
|:---|:---|
| **Month** | 3 — November 2026 |
| **Status** | Active Working Manuscript |
| **Domain** | Multi-Vector Retrieval, Storage Engines, Log-Structured Merge Trees, Asynchronous I/O |

---

## 1. Executive Abstract & Falsifiable Question


**Core Falsifiable Question**:
> *How does the write-amplification and query-latency Pareto frontier of centroid-pruned inverted lists (PLAID) compare against Fixed-Dimensional Projections (MUVERA FDE) inside a dynamic Log-Structured Merge (LSM) vector store under continuous $10{,}000	ext{ writes/second}$ streaming ingestion?*

---

## 2. Theoretical Architecture

1. **MaxSim Multi-Vector Bottleneck**:
   $$\operatorname{Score}(Q, D) = \sum_{i=1}^{|Q|} \max_{j=1}^{|D|} \mathbf{q}_i^T \mathbf{d}_j$$
   * For document collections with $N=10^6$ items and $|D|=128$ tokens, evaluating all pairs requires $1.28 	imes 10^8$ vector dot products per query ($>150	ext{ ms}$).
2. **PLAID Centroid Inverted Lists**:
   * Prunes candidate vectors via multi-stage centroid filtering ($k$-means inverted lists on token space), retrieving only top candidates for fine-grained MaxSim.
3. **MUVERA Fixed-Dimensional Encodings (FDE)**:
   * Projects the dynamic multi-vector set $\{ \mathbf{d}_j \}_{j=1}^{|D|}$ into a single unified high-dimensional vector $\mathbf{v}_{	ext{FDE}} \in \mathbb{R}^{D_{	ext{fde}}}$ using randomized orthogonal partitions (FWHT), reducing late interaction directly to Single-Vector MIPS!
4. **Dynamic LSM Storage Engine**:
   * MemTable (in-memory lock-free skiplist) $	o$ WAL direct append $	o$ Immutable SSTables $	o$ Background multi-level compaction.

---

## 3. Experimental Parameters
* **Ingestion Rates**: Continuous streaming insertion at $1	ext{K}$, $5	ext{K}$, and $10	ext{K}$ multi-vectors/sec.
* **Corpus**: BEIR / MS MARCO multi-vector subset + synthetic SIGINT pulse intercept tracks.
* **Metrics**: P50 / P99 query latency during active compaction, Write Amplification Factor (WAF), and Mean Reciprocal Rank (MRR@10).

---

## 4. Reproducibility
```bash
./build/benchmarks/bench_streaming_lsm --threads=16 --write_rate=10000 --eval_interval=5s
```
