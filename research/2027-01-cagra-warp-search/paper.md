# Paging vs. Quantizing LLM KV Caches at Long Contexts: Memory Fragmentation, Dequantization Overhead, and Serving Throughput

| Metadata | Specification |
|:---|:---|
| **Month** | 5 — January 2027 |
| **Status** | Empirical Benchmark Report |
| **Domain** | LLM Serving Systems, GPU Memory Management, Extreme Quantization |

---

## 1. Executive Abstract & Falsifiable Question

2. **PagedAttention Virtual Memory**:
   * Organizes KV cache into physical blocks of fixed size ($16$ tokens). Eliminates internal and external fragmentation ($<4\%$ memory waste).
3. **3-bit PolarQuant Compression**:
   * Applies orthogonal random rotations (destroying outlier coordinate bias) followed by 3-bit spherical quantization, slashing KV cache footprint by **$>5.3	imes$**.

---

## 3. Experimental Protocol & Hardware
* **Hardware**: Edge NVIDIA Jetson Orin AGX (32GB) & Server NVIDIA A100/H100.
* **Models**: Open weights models (Llama-3.2-1B/3B, Qwen-2.5-7B).
* **Sweeps**: Context lengths $4	ext{K} 	o 16	ext{K} 	o 32	ext{K} 	o 64	ext{K} 	o 128	ext{K}$ tokens; batch concurrency $B \in [1, 32]$.

---

## 4. Reproducibility
```bash
./build/benchmarks/bench_kv_cache --model=qwen2.5-1.5b --context=32768 --quant=3bit
```
