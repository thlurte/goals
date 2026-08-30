# {Working title}

| | |
|:---|:---|
| **Month** | {N} — {Mon YYYY} |
| **Publish by** | {date} |
| **Folder** | `research/{YYYY-MM-slug}/` |
| **Primary artifact** | {secan target / figure} |
| **Status** | draft |

Copy this file to `YYYY-MM-<slug>/paper.md`. Fill every section. Do not add extra top-level headings.

## 1. Question

One sentence. Falsifiable.

>

## 2. Method

Reproducible from `secan` (or a named companion repo). Hardware, commit, flags, datasets.

| Item | Value |
|:---|:---|
| CPU / GPU | |
| `secan` commit | |
| Build | e.g. `Release`, `-march=native` |
| Dataset | |
| Metrics | |

### Protocol

Steps another engineer can follow.

1.
2.

## 3. Experiments

What you ran (or will run). One row per experiment.

| ID | Setup | What you measure |
|:---|:---|:---|
| E1 | | |

## 4. Results

≥1 figure in `figures/`. Paste numbers here; do not leave “see notebook.”

**Figure 1.** `{caption}` → `figures/{name}.png`

| | |
|:---|:---|
| | |

## 5. Baseline

Named: `faiss` / `hnswlib` / scalar / paper method. Same dataset and metric as §4.

| System | Metric | Notes |
|:---|:---|:---|
| **This work** | | |
| **Baseline** | | |

## 6. Limitations

Honest paragraph. What the numbers do *not* claim.

## 7. Reproduce

```bash
# clone, build, run, plot
```
