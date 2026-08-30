# 28-Week Curriculum (Sep 2026 – Mar 2027)

**Specialty**: vector search / ANN systems (`secan`), not REST APIs and not agent frameworks.  
**Weekdays**: `secan` / CUDA only. **Sat 14:00–18:00**: one DL afternoon. **Sundays**: monthly research.

| Block | Weeks | Calendar | Deliverable |
|:---|:---|:---|:---|
| **I — Vector Search** | 1–16 | Sep–Dec 2026 | Composed ANN spine → `v1.2-vs-spine-complete` |
| **II — GPU specialization** | 17–28 | Jan–Mar 2027 | FA-2, KV paging, multi-GPU, ColPali → `v2.0` |

## Daily cadence (Mon–Fri)

1. **06:00–07:30** — Pure math  
2. **07:30–08:30** — Systems reading  
3. **20:30–23:00** — `secan` / CUDA (no weekday DL)

## Weekend rhythm

1. **Sat 09:00–13:00** — lab note ([essays](essays.md))  
2. **Sat 14:00–18:00** — DL ([landings](landings.md#dl-weekend-landings-sat-14001800-only))  
3. **Sun 09:00–13:00** — monthly research ([`../research/`](../research/README.md))  
4. **Last weekend** — publish monthly paper  

## Map

| Doc | What |
|:---|:---|
| [Hard landings](landings.md) | Deferred ledger, VS composition, DL weekends |
| [Architecture roadmap](roadmap.md) | Macro blueprint for `secan` |
| [Essay schedule](essays.md) | 28 lab-note titles (don’t polish all) |
| [Week 1 execution](week-01/execution.md) | Hour-by-hour for Sep 1–7 |
| [Prerequisites](../README.md#entry-prerequisites-before-sep-1) | Hardware / datasets / tooling |

## Weeks by month

| Month | File | Weeks |
|:---|:---|:---|
| Sep 2026 | [month-01-sep.md](weeks/month-01-sep.md) | 1–4 |
| Oct 2026 | [month-02-oct.md](weeks/month-02-oct.md) | 5–8 |
| Nov 2026 | [month-03-nov.md](weeks/month-03-nov.md) | 9–12 |
| Dec 2026 | [month-04-dec.md](weeks/month-04-dec.md) | 13–16 |
| Jan 2027 | [month-05-jan.md](weeks/month-05-jan.md) | 17–20 |
| Feb 2027 | [month-06-feb.md](weeks/month-06-feb.md) | 21–24 |
| Mar 2027 | [month-07-mar.md](weeks/month-07-mar.md) | 25–28 |

## Pillars

```
 ┌──────────────────────────────────────────────────────────────────────────────────────────────────┐
 │                               PILLAR 1: PURE MATHEMATICS (90 MIN/DAY)                            │
 │ • Sep: Trig + Calc · Oct: Multivariable · Nov: Linear Algebra · Dec: Probability                 │
 │ • Jan: Limit theorems / stats · Feb: Convex + spectral · Mar: GPU synthesis                      │
 └────────────────────────┬─────────────────────────────────────────┬───────────────────────────────┘
                          │                                         │
                          ▼                                         ▼
 ┌────────────────────────────────────────┐     ┌───────────────────────────────────────────────────┐
 │   PILLAR 2: DEEP LEARNING (Sat only)   │     │  PILLAR 3: secan (Mon–Fri nights)                 │
 │ • RoPE / GQA / naive KV                │────►│ • SIMD, quant, HNSW, IVF, DiskANN, LSM, WAND      │
 │ • InfoNCE → ONNX/ORT                   │     │ • ColBERT / PLAID / MUVERA FDE→MIPS               │
 │ • ColBERT, CLIP→ColPali                │     │ • IVF-PQ / HNSW-SQ · FA / PagedAttention          │
 └────────────────────────────────────────┘     └───────────────────────────────────────────────────┘
```

Root index: [`../README.md`](../README.md).
