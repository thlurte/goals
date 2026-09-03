# Mitigating Recall Collapse in Filtered Approximate Nearest Neighbor Graphs: An Empirical Evaluation of ACORN vs. Iterative Post-Filtering Across Selectivity Spectrums

| Metadata | Specification |
|:---|:---|
| **Month** | 6 — February 2027 |
| **Status** | Active Working Manuscript |
| **Domain** | Graph Navigation, Predicate Filtering, Relational-Vector Systems |
| **Dual-Use Defense Application** | **JADC2 Multilevel Security (MLS) & Target Clearance Filtering** |

---

## 1. Executive Abstract & Falsifiable Question

In Joint All-Domain Command and Control (JADC2), target intelligence carries strict compartmented metadata (Security Clearance: `TOP_SECRET//NOFORN`, Sensor Unit: `RADAR_5`, Geolocation: `SECTOR_4`). When queries execute under restrictive clearances, up to $99.9\%$ of index nodes are masked out ($P(	ext{pass}) < 0.1\%$). Under such conditions, standard HNSW graphs suffer **catastrophic recall collapse** (dropping to $<15\%$ recall) because the greedy beam search becomes trapped in disconnected islands of invalid nodes.

**Core Falsifiable Question**:
> *Does constructing predicate-aware multi-hop bridge edges (ACORN) prevent recall collapse across extreme selectivity spectrums ($P(\text{pass}) \in [1.0, 0.0001]$), maintaining $>90\%$ Recall@10 with $<2.0\times$ search latency penalty compared to unconstrained graphs?*

---

## 2. Mathematical Graph Theory

1. **Recall Collapse Probability**:
   * In a small-world graph with vertex degree $M$ and Bernoulli predicate probability $\sigma = P(	ext{pass})$:
     $$P(	ext{Node Isolated}) = (1 - \sigma)^M$$
   * When $\sigma = 0.01$ and $M = 32$, $P(	ext{Node Isolated}) pprox 72.5\%$. Graph traversal halts prematurely at local dead ends.
2. **ACORN 2-Hop Predicate Routing**:
   * Extends the neighborhood to include 2-hop structural bridge neighbors:
     $$N_{	ext{ACORN}}(p) = N(p) \cup \{ v \in N(u) : u \in N(p) \land \operatorname{Predicate}(v) = 	ext{true} \}$$
   * Guarantees small-world connectivity across valid predicate subgraphs.

---

## 3. Experimental Parameters
* **Filter Selectivity**: Exponential sweep $\sigma \in \{1.0, 0.5, 0.1, 0.01, 0.001, 0.0001\}$.
* **Algorithms**:
  1. Standard HNSW with Post-Filtering.
  2. Iterative Expansion Post-Filtering.
  3. Pre-filtered Inverted List Brute-Force.
  4. ACORN Predicate-Aware Small-World Index.

---

## 4. Reproducibility
```bash
./build/benchmarks/bench_filtered_search --selectivity=0.001 --index=acorn
```
