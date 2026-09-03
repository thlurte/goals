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
4. **Sun 13:00–14:00** — `limbed` / `ggmbed` maintenance ([`embed-runtimes`](../projects/embed-runtimes.md)) (30–60 min only; never weekdays)  
5. **Last weekend** — publish monthly paper  

## Map

| Doc | What |
|:---|:---|
| [Hard landings](landings.md) | Deferred ledger, VS composition, DL weekends |
| [Architecture roadmap](roadmap.md) | Master blueprint: systems architecture, profiling playbook & canonical proofs |
| [Essay schedule](essays.md) | 28 lab-note titles (don’t polish all) |
| [Weeks & Daily Actions](weeks/month-01-sep.md) | Day-by-day tables, actions, stretch & time traps |
| [Prerequisites](../README.md#entry-prerequisites-before-sep-1) | Hardware / datasets / tooling |

## Weeks & Playbooks by Month

| Month | Month Dashboard | Weekly Execution Playbooks | Daily Runbooks |
|:---|:---|:---|:---|
| **Sep 2026** (Month 1) | [month-01-sep.md](weeks/month-01-sep.md) | [Week 01](weeks/week-01.md) · [Week 02](weeks/week-02.md) · [Week 03](weeks/week-03.md) · [Week 04](weeks/week-04.md) | [Days 001–028](days/month-01/) |
| **Oct 2026** (Month 2) | [month-02-oct.md](weeks/month-02-oct.md) | [Week 05](weeks/week-05.md) · [Week 06](weeks/week-06.md) · [Week 07](weeks/week-07.md) · [Week 08](weeks/week-08.md) | [Days 029–056](days/month-02/) |
| **Nov 2026** (Month 3) | [month-03-nov.md](weeks/month-03-nov.md) | [Week 09](weeks/week-09.md) · [Week 10](weeks/week-10.md) · [Week 11](weeks/week-11.md) · [Week 12](weeks/week-12.md) | [Days 057–084](days/month-03/) |
| **Dec 2026** (Month 4) | [month-04-dec.md](weeks/month-04-dec.md) | [Week 13](weeks/week-13.md) · [Week 14](weeks/week-14.md) · [Week 15](weeks/week-15.md) · [Week 16](weeks/week-16.md) | [Days 085–112](days/month-04/) |
| **Jan 2027** (Month 5) | [month-05-jan.md](weeks/month-05-jan.md) | [Week 17](weeks/week-17.md) · [Week 18](weeks/week-18.md) · [Week 19](weeks/week-19.md) · [Week 20](weeks/week-20.md) | [Days 113–140](days/month-05/) |
| **Feb 2027** (Month 6) | [month-06-feb.md](weeks/month-06-feb.md) | [Week 21](weeks/week-21.md) · [Week 22](weeks/week-22.md) · [Week 23](weeks/week-23.md) · [Week 24](weeks/week-24.md) | [Days 141–168](days/month-06/) |
| **Mar 2027** (Month 7) | [month-07-mar.md](weeks/month-07-mar.md) | [Week 25](weeks/week-25.md) · [Week 26](weeks/week-26.md) · [Week 27](weeks/week-27.md) · [Week 28](weeks/week-28.md) | [Days 169–196](days/month-07/) |

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
