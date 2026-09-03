# Paging vs. Quantizing LLM KV Caches at Long Contexts: Memory Fragmentation, Dequantization Overhead, and Serving Throughput

| Metadata | Specification |
|:---|:---|
| **Month** | 5 — January 2027 |
| **Status** | Active Working Manuscript |
| **Domain** | LLM Serving Systems, GPU Memory Management, Extreme Quantization |
| **Dual-Use Defense Application** | **Autonomous Drone Swarm Mission Planning & Edge Decision LLMs** |

---

## 1. Executive Abstract & Falsifiable Question

Autonomous unmanned combat swarms operating in GPS-denied environments require onboard tactical reasoning models running over long operational histories (hours of telemetry, rules of engagement, sensor histories). Under $32	ext{K}	ext{–}128	ext{K}$ token context lengths, Key-Value (KV) cache memory completely exhausts the 16GB–32GB memory envelope of edge hardware (NVIDIA Jetson Orin AGX).

**Core Falsifiable Question**:
> *Does extreme 3-bit polar quantization (TurboQuant/PolarQuant) outperform non-contiguous virtual memory paging (PagedAttention) in serving throughput and maximum batch concurrency at $128\text{K}$ context lengths, and what is the exact boundary where dequantization compute overhead begins to degrade tokens/second generation latency?*

---

## 2. Technical Model

1. **KV Cache Memory Footprint**:
   $$	ext{Memory}_{	ext{KV}} = 2 	imes B 	imes L 	imes N_{	ext{layers}} 	imes N_{	ext{heads}} 	imes D_{	ext{head}} 	imes b_{	ext{precision}}$$
   * At $L = 128	ext{K}$ context with 16-bit precision, a single sequence consumes **$>32	ext{ GB}$ of VRAM**, exceeding edge device physical limits.
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
