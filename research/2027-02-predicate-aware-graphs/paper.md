# Mitigating Recall Collapse in Filtered Approximate Nearest Neighbor Graphs: An Empirical Evaluation of ACORN vs. Iterative Post-Filtering Across Selectivity Spectrums

| Metadata | Specification |
|:---|:---|
| **Month** | 6 — February 2027 |
| **Status** | Active Working Manuscript |
| **Domain** | Graph Navigation, Predicate Filtering, Relational-Vector Systems |

---

## 1. Executive Abstract & Falsifiable Question

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
