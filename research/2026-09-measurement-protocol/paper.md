# Month 1 Research — Measurement Before Optimization

**Publish deadline**: Sunday, September 27, 2026  
**Working title**: *Measurement Before Optimization: A Reproducible Protocol for Vector Distance Microbenchmarks*

## One-sentence question
Can we publish a noise-aware, dead-code-safe microbenchmark protocol for L2/cosine kernels that other engineers can reproduce within 5% IPC on the same CPU?

## Weekend build checklist
- [ ] Week 1 Sat/Sun: scaffold `paper.md`; capture first Google Benchmark + `perf stat` rows
- [ ] Week 2 Sat/Sun: AVX2 vs scalar comparison table; document `DoNotOptimize` / clobber pitfalls
- [ ] Week 3 Sat/Sun: dim sweep $D \in \{64,128,768,1536\}$; cache-miss commentary
- [ ] Week 4 Sat: Essay 4 as lab note; Sun: **publish**

## Publish bar
Question · method · ≥1 figure · named baseline · limitations — see [../README.md](../README.md).
