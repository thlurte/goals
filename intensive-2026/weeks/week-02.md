# Week 2: Multi-threading, Synchronization & Concurrency
> **Dates**: October 26 – November 1, 2026  
> **Core Focus**: Thread lifecycles, race conditions, atomic operations, C++ memory order (`acquire`/`release`), lock-free queues, and custom thread pools.

---

### Day 8 (Mon, Oct 26): Thread Management & Mutex Synchronization
- 📖 **Reading**: **[C++Concurrency]** (Anthony Williams) — **Chapters 2 & 3** (pp. 15–72). Managing threads, passing arguments, transferring ownership, protecting shared data with mutexes.
- 💻 **Drills (`day_08_drills.md`)**:
  1. `drill_08a_thread_guard.cpp`: Build a custom RAII `ThreadGuard` that ensures `.join()` is called even if an exception is thrown.
  2. `drill_08b_mutex_deadlock.cpp`: Reproduce a deadlock with two mutexes (`lock(m1); lock(m2)` vs `lock(m2); lock(m1)`). Fix it using `std::scoped_lock` / deadlock avoidance algorithms.
  3. `drill_08c_thread_safe_stack.cpp`: Build a thread-safe stack with mutex and condition variable, handling empty-stack pop exceptions.
- 🛠️ **`secan`**: Design the thread management abstraction for vector indexing.

---

### Day 9 (Tue, Oct 27): Atomic Operations & The C++ Memory Model
- 📖 **Reading**: **[C++Concurrency]** — **Chapter 5** (pp. 115–150). Atomic types, operations, and the C++ memory model.
- 💻 **Drills (`day_09_drills.md`)**:
  1. `drill_09a_atomic_flag_spinlock.cpp`: Implement a custom `Spinlock` using `std::atomic_flag` (`test_and_set` with `std::memory_order_acquire`, `clear` with `std::memory_order_release`).
  2. `drill_09b_acquire_release_handshake.cpp`: Build a two-thread message passer where Thread 1 publishes data and flags ready with `release`, and Thread 2 reads flag with `acquire` and accesses data without a mutex.
  3. `drill_09c_cas_loop_counter.cpp`: Implement a lock-free saturating counter using `compare_exchange_weak` in a loop.
- 🛠️ **`secan`**: Implement lock-free index state indicators (`UNINITIALIZED`, `BUILDING`, `READY`, `DIRTY`).

---

### Day 10 (Wed, Oct 28): Work Queues & Custom Thread Pool
- 📖 **Reading**: **[C++Concurrency]** — **Chapter 9** (pp. 275–305). Advanced thread management, thread pools, and work stealing.
- 💻 **Drills (`day_10_drills.md`)**:
  1. `drill_10a_blocking_queue.cpp`: Thread-safe bounded blocking queue using `std::mutex` and `std::condition_variable` (`push`, `pop`, `shutdown`).
  2. `drill_10b_production_thread_pool.cpp`: Production-grade `ThreadPool` using `std::vector<std::thread>`, `std::queue<std::function<void()>>`, and `submit()` returning `std::future<R>` via `std::packaged_task`.
  3. `drill_10c_parallel_for.cpp`: Implement `parallel_for(start, end, func)` that divides a range across threads in your thread pool.
- 🛠️ **`secan`**: Integrate your `ThreadPool` into `secan` for batch distance scoring.

---

### Day 11 (Thu, Oct 29): Reader-Writer Locks & Concurrent Bitset
- 📖 **Reading**: **[ArtOfProg]** (Fedor Pikus) — **Chapter 9** (pp. 280–310). Concurrency, lock contention, reader-writer locks, and lock-free data structures.
- 💻 **Drills (`day_11_drills.md`)**:
  1. `drill_11a_shared_mutex.cpp`: Benchmark `std::shared_mutex` (readers-writer lock) under 95% reads / 5% writes vs plain `std::mutex`.
  2. `drill_11b_concurrent_bitset.cpp`: Implement `ConcurrentBitset` using an array of `std::atomic<uint64_t>` for multi-threaded visited tracking. Implement atomic `test_and_set(index)`.
  3. `drill_11c_lock_free_spsc.cpp`: Single-Producer Single-Consumer (SPSC) lock-free ring buffer using atomic head/tail indices.
- 🛠️ **`secan`**: Use `ConcurrentBitset` as the visited set in parallel graph exploration.

---

### Day 12 (Fri, Oct 30): Lock Contention & ThreadSanitizer
- 📖 **Reading**: **[ArtOfProg]** — **Chapter 10** ("Fine-Grained Concurrency", pp. 315–340).
- 💻 **Drills (`day_12_drills.md`)**:
  1. `drill_12a_striped_hashmap.cpp`: Implement a concurrent hash map with striped / sharded locks (16 independent mutexes protecting hash buckets).
  2. `drill_12b_tsan_data_race.cpp`: Intentionally trigger a data race. Compile with `-fsanitize=thread`. Learn to parse TSAN race reports and eliminate the race with proper memory ordering.
  3. `drill_12c_parallel_batch_benchmark.cpp`: Benchmark ingesting 100,000 vectors across 1, 2, 4, 8, 12 threads. Measure parallel scaling efficiency.
- 🛠️ **`secan`**: Run `-fsanitize=thread` across `secan` multi-threaded tests.

---

### Day 13 (Sat, Oct 31): Concurrency Consolidation
- 💻 **Drills (`day_13_drills.md`)**:
  1. `drill_13a_lock_free_stack.cpp`: Implement Treiber's Lock-Free Stack using `compare_exchange_weak`.
  2. `drill_13b_aba_problem.cpp`: Demonstrate why naive lock-free stacks suffer from the ABA problem. Explain how tagged pointers or hazard pointers prevent it.
  3. `drill_13c_thread_affinity.cpp`: Pin worker threads to specific CPU cores using `pthread_setaffinity_np` and measure latency jitter reduction.

---

### Day 14 (Sun, Nov 1): Timed Concurrency Exam (No Notes)
- ⏱️ **45-minute timed coding exam**: Write a thread-safe bounded queue and a basic thread pool completely from scratch from a blank file with zero compiler warnings.
