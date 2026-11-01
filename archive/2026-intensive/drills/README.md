# 💻 Systems Engineering Micro-Drills
> **Core Principle**: No boilerplates. No code templates. You code every single drill from a blank `.cpp` file based on the specification markdown.

---

## 📂 Drill Specifications by Week

- **[Week 1: C++ Memory Mastery, RAII & Custom Allocators](week-01/)**
  - **[Day 1 Specs](week-01/day_01_drills.md)**: Bump Arena, `malloc` Benchmark, Chained Arena (`drill_01a`, `drill_01b`, `drill_01c`)
  - **Day 2 Specs**: Smart Pointers from Scratch (`UniquePtr`, `SharedPtr`, Rule-of-Five)
  - **Day 3 Specs**: Cache Strides, Transpose Blocking & Contiguous Dataset (`drill_03a`, `drill_03b`, `drill_03c`)
  - **Day 4 Specs**: Stack Vectors (`FixedVector`, `SmallVector`, `AlignedAllocator`)
  - **Day 5 Specs**: False Sharing Reproduction & Elimination with `alignas(64)`
  - **Day 6 Specs**: Intrusive Freelist / Slab Pool & Sanitizers (`-fsanitize=address`)
  - **Day 7 Specs**: Timed Self-Audit Exam (45 min, no notes)

---

## 🛠️ Verification Workflow for Each Drill

1. Read the exact textbook pages listed in the day's `.md` file.
2. Read the drill specification.
3. Open a brand new file, e.g., `drills/week-01/drill_01a_arena.cpp`.
4. Implement the class and verification tests completely from scratch.
5. Compile strictly with:
   ```bash
   g++ -std=c++20 -O3 -Wall -Wextra -Werror <file>.cpp -o <binary> && ./<binary>
   ```
6. For memory drills, verify with AddressSanitizer:
   ```bash
   g++ -std=c++20 -fsanitize=address -g <file>.cpp -o <binary> && ./<binary>
   ```
