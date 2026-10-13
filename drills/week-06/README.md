# 🥋 Week 06 Systems Mastery Suite: 100 Modern C++ Drills

Comprehensive, first-principles micro-drills covering production systems programming across three non-negotiable pillars for vector search and AI engine engineering:
1. **Memory, Lifetimes & RAII (Drills 01–35, 51–65)**: From hardware stack/heap mechanics, pointers, and memory poisoning to custom allocators, placement `new`, slab allocators, and eliminating `std::shared_ptr` anti-patterns.
2. **Memory Alignment, Cache Hierarchy & Raw Buffers (Drills 21–35, 66–80)**: Struct padding, `alignas(64)`, `posix_memalign`, AVX2 load/unaligned penalties, software prefetching (`_mm_prefetch`), non-temporal stores, and zero-copy binary serialization.
3. **Concurrency, Locks, Atomics & Cache Coherence (Drills 36–50, 81–100)**: Mutexes, readers-writer starvation prevention, `std::atomic` CAS loops, eliminating false sharing, hazard pointers, RCU, lock-free SPSC queues, barriers, and pinned worker pools.

---

## 🏃 Quick Run Command
Every drill is self-contained with modern compiler flags:
```bash
cd drills/week-06
g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_01_day038_mem_basic_raii_stack_wrapper.cpp -o drill && ./drill
```

---

## 📑 Complete 100-Drill Master Inventory

### 🧠 Part I: Memory & Lifetimes / RAII (Drills 01–20, 51–65)
* **01**: `drill_01_day038_mem_basic_raii_stack_wrapper.cpp` — Stack-managed heap resource, Rule of 0 / Rule of 3, deleting copy operators.
* **02**: `drill_02_day038_mem_unique_ptr_ownership_transfer.cpp` — `std::unique_ptr` exclusive ownership, `std::make_unique`, `std::move`.
* **03**: `drill_03_day038_mem_unique_ptr_array_specialization.cpp` — `std::unique_ptr<T[]>` vs scalar `delete` mismatch UB.
* **04**: `drill_04_day038_mem_move_semantics_and_exchange.cpp` — Move constructor & move assignment using `std::exchange` to prevent double-frees.
* **05**: `drill_05_day038_mem_use_after_free_prevention.cpp` — Preventing dangling pointers & use-after-free, non-owning view boundaries.
* **06**: `drill_06_day038_mem_unique_ptr_custom_deleter_c_file.cpp` — Wrapping C APIs (`FILE*`, `fclose`) with custom deleter functors.
* **07**: `drill_07_day038_mem_custom_deleter_empty_base_optimization.cpp` — Empty Base Class Optimization (EBCO): stateless functor vs function pointer size overhead.
* **08**: `drill_08_day038_mem_shared_ptr_control_block_overhead.cpp` — `std::shared_ptr` mechanics: control block allocation & `std::make_shared`.
* **09**: `drill_09_day038_mem_shared_ptr_antipattern_unique_observer.cpp` — `shared_ptr` anti-pattern: refactoring to `std::unique_ptr` ownership + raw pointer observer (`T*`).
* **10**: `drill_10_day038_mem_cyclic_reference_weak_ptr.cpp` — Breaking cyclic reference memory leaks with `std::weak_ptr` and `lock()`.
* **11**: `drill_11_day038_mem_enable_shared_from_this.cpp` — Preventing double control-block double-frees with `std::enable_shared_from_this`.
* **12**: `drill_12_day038_mem_polymorphic_virtual_destructor.cpp` — Preventing partial destruction UB with `virtual ~Base()`.
* **13**: `drill_13_day038_mem_rule_of_five_deep_copy_array.cpp` — Complete Rule of Five implementation (Deep Copy vs Move).
* **14**: `drill_14_day038_mem_copy_and_swap_idiom.cpp` — Strong exception safety using pass-by-value and `swap()`.
* **15**: `drill_15_day038_mem_scope_guard_defer.cpp` — Scope Guard / Defer idiom with dismissible transactional commit/rollback.
* **16**: `drill_16_day038_mem_intrusive_ref_counting.cpp` — Intrusive reference counted pointer (`IntrusivePtr`) for cache locality.
* **17**: `drill_17_day038_mem_fixed_size_slab_freelist.cpp` — Fixed-size slab allocator with embedded in-chunk free list.
* **18**: `drill_18_day038_mem_arena_bump_placement_new.cpp` — Arena bump allocator with placement `new` and explicit destructor calls.
* **19**: `drill_19_day038_mem_small_buffer_optimization_sso.cpp` — Small Buffer Optimization (SSO / SBO) inline stack buffer vs heap fallback.
* **20**: `drill_20_day038_mem_pimpl_unique_ptr_destructor.cpp` — Pimpl idiom with `std::unique_ptr<Impl>` and complete destructor location.
* **51**: `drill_51_day038_mem_pointer_arithmetic_stride.cpp` — Pointer arithmetic & stride calculation: `char*` vs `T*`.
* **52**: `drill_52_day038_mem_double_free_trap_and_fix.cpp` — The double-free trap: shallow copy vs deep copy.
* **53**: `drill_53_day038_mem_use_after_free_poisoning.cpp` — Use-after-free & debug pointer poisoning (`0xDEADBEEF`).
* **54**: `drill_54_day038_mem_leak_tracker_global_new.cpp` — Programmatic memory leak detection via overloaded `operator new`.
* **55**: `drill_55_day038_mem_self_assignment_hazard.cpp` — Self-assignment hazard & safe `operator=` guards.
* **56**: `drill_56_day038_mem_unique_ptr_mmap_deleter.cpp` — `std::unique_ptr` custom deleter for POSIX `mmap` / `munmap`.
* **57**: `drill_57_day038_mem_shared_ptr_aliasing_constructor.cpp` — `std::shared_ptr` aliasing constructor for sub-object sharing.
* **58**: `drill_58_day038_mem_explicit_constructors_conversions.cpp` — `explicit` keyword: preventing implicit conversion heap allocations.
* **59**: `drill_59_day038_mem_lifetime_extension_temporaries.cpp` — Lifetime extension rules: `const T&` vs dangling `std::string_view`.
* **60**: `drill_60_day038_mem_rvo_nrvo_move_pessimization.cpp` — Return Value Optimization (RVO / NRVO) vs move pessimization.
* **61**: `drill_61_day038_mem_placement_new_array_destruction.cpp` — Placement `new[]` vs scalar placement: reverse destruction order.
* **62**: `drill_62_day038_mem_pmr_monotonic_buffer_resource.cpp` — Polymorphic memory resources (`std::pmr::monotonic_buffer_resource`).
* **63**: `drill_63_day038_mem_span_subspan_bounds_safety.cpp` — Zero-copy buffer windowing with `std::span` and `subspan`.
* **64**: `drill_64_day038_mem_observer_token_generation.cpp` — Generational handle pattern: detecting stale observers.
* **65**: `drill_65_day038_mem_custom_pthread_mutex_raii.cpp` — Bare-metal RAII: wrapping C `pthread_mutex_t` from first principles.

---

### ⚡ Part II: Memory Alignment, Cache Hierarchy & Raw Buffers (Drills 21–35, 66–80)
* **21**: `drill_21_day038_align_struct_padding_and_ordering.cpp` — Struct padding holes, `alignof`, `offsetof`, and field reordering.
* **22**: `drill_22_day038_align_alignas_specifier.cpp` — Enforcing 32-byte (AVX2) and 64-byte (cache line / AVX-512) alignment with `alignas`.
* **23**: `drill_23_day038_align_posix_memalign_aligned_alloc.cpp` — Dynamic aligned heap allocation with `posix_memalign`.
* **24**: `drill_24_day038_align_runtime_alignment_check.cpp` — Fast runtime alignment checking using bitwise mask `(addr & (align - 1)) == 0`.
* **25**: `drill_25_day038_align_std_align_custom_buffer.cpp` — Carving aligned sub-buffers out of unaligned memory with `std::align`.
* **26**: `drill_26_day038_align_raw_byte_serialization_reinterpret.cpp` — Serializing POD structs to byte buffers via `reinterpret_cast`.
* **27**: `drill_27_day038_align_strict_aliasing_and_bit_cast.cpp` — Strict aliasing violations vs safe type punning with `std::bit_cast`.
* **28**: `drill_28_day038_align_avx2_load_vs_loadu.cpp` — AVX2 aligned load (`_mm256_load_ps`) crash hazard vs unaligned load (`_mm256_loadu_ps`).
* **29**: `drill_29_day038_align_cache_line_split_penalty.cpp` — Cache line splits: detecting 32-byte loads straddling 64-byte cache line boundaries.
* **30**: `drill_30_day038_align_vector_dimension_pitch_padding.cpp` — Vector dimension pitch padding for aligned row SIMD loops.
* **31**: `drill_31_day038_align_placement_new_aligned_storage.cpp` — Placement `new` into `alignas(64)` raw byte array storage.
* **32**: `drill_32_day038_align_mmap_page_aligned_io.cpp` — POSIX `mmap` zero-copy memory mapping and 4096-byte page alignment.
* **33**: `drill_33_day038_align_type_punning_fvecs_binary_stream.cpp` — Zero-copy parsing of `.fvecs` binary streams using `std::span`.
* **34**: `drill_34_day038_align_sq4_nibble_offset_math.cpp` — 4-bit scalar quantization nibble offset indexing and bitshift calculations.
* **35**: `drill_35_day038_align_cache_aligned_matrix_buffer.cpp` — Production 64-byte cache-aligned 2D matrix buffer class with pitch padding.
* **66**: `drill_66_day038_align_cache_stride_spatial_locality.cpp` — Spatial locality: cache line stride 1 vs stride 16.
* **67**: `drill_67_day038_align_hardware_prefetcher_stream.cpp` — Hardware stream prefetcher: sequential vs pointer chasing.
* **68**: `drill_68_day038_align_software_prefetch_mm_prefetch.cpp` — Software prefetching via `_mm_prefetch` intrinsics.
* **69**: `drill_69_day038_align_non_temporal_stores_stream.cpp` — Non-temporal stores (`_mm256_stream_ps`) for cache bypassing.
* **70**: `drill_70_day038_align_simd_unaligned_loop_peeling.cpp` — SIMD loop alignment peeling: head, aligned body, and tail.
* **71**: `drill_71_day038_align_binary_quant_bit_packing.cpp` — 1-bit binary quantization: sign packing into `uint64_t`.
* **72**: `drill_72_day038_align_2bit_quant_packing.cpp` — 2-bit scalar quantization: packing 4 values per byte.
* **73**: `drill_73_day038_align_endianness_byte_swapping.cpp` — Endianness detection & `std::byteswap` / `__builtin_bswap32`.
* **74**: `drill_74_day038_align_posix_memalign_mprotect.cpp` — Page alignment & memory protection: `posix_memalign` + `mprotect`.
* **75**: `drill_75_day038_align_flexible_array_posting_list.cpp` — Contiguous posting list layout without pointer indirection.
* **76**: `drill_76_day038_align_row_major_vs_column_major.cpp` — Row-Major vs Column-Major layout for SIMD dot products.
* **77**: `drill_77_day038_align_cache_oblivious_transposition.cpp` — Cache-aware blocked matrix transposition.
* **78**: `drill_78_day038_align_zero_copy_dataset_header_align.cpp` — Zero-copy serialization invariant verification for headers.
* **79**: `drill_79_day038_align_simd_movemask_filtering.cpp` — SIMD bitmask extraction: `_mm256_movemask_ps`.
* **80**: `drill_80_day038_align_cache_aligned_circular_buffer.cpp` — Isolated cache lines in circular ring buffers.

---

### 🔒 Part III: Concurrency, Locks, Atomics & Lock-Free Primitives (Drills 36–50, 81–100)
* **36**: `drill_36_day038_concurrency_mutex_and_lock_guard.cpp` — Critical section protection using `std::mutex` and `std::lock_guard`.
* **37**: `drill_37_day038_concurrency_unique_lock_fine_grained.cpp` — Fine-grained locking with `std::unique_lock` and early unlock.
* **38**: `drill_38_day038_concurrency_deadlock_prevention_scoped_lock.cpp` — Deadlock prevention with `std::scoped_lock` (ABBA lock ordering safe).
* **39**: `drill_39_day038_concurrency_shared_mutex_readers_writer.cpp` — Readers-writer lock with `std::shared_mutex` and `std::shared_lock`.
* **40**: `drill_40_day038_concurrency_atomic_fetch_operations.cpp` — Lock-free counter using `std::atomic` `fetch_add` / `fetch_sub`.
* **41**: `drill_41_day038_concurrency_spinlock_atomic_flag.cpp` — User-space TTAS spinlock with `std::atomic_flag` and `PAUSE` hint.
* **42**: `drill_42_day038_concurrency_lock_free_cas_max_accumulator.cpp` — Lock-free running max accumulator using `compare_exchange_weak`.
* **43**: `drill_43_day038_concurrency_false_sharing_demonstration.cpp` — Demonstrating false sharing cache line contention across threads.
* **44**: `drill_44_day038_concurrency_false_sharing_elimination_alignas.cpp` — Eliminating false sharing with `alignas(64)` cache line padding.
* **45**: `drill_45_day038_concurrency_relaxed_vs_seq_cst_ordering.cpp` — Memory ordering trade-offs: `memory_order_relaxed` vs `memory_order_seq_cst`.
* **46**: `drill_46_day038_concurrency_acquire_release_synchronization.cpp` — Acquire-release synchronization for lock-free producer-consumer publishing.
* **47**: `drill_47_day038_concurrency_producer_consumer_cond_var.cpp` — Bounded blocking queue using `std::condition_variable` and mutex.
* **48**: `drill_48_day038_concurrency_lock_free_spsc_ring_buffer.cpp` — Lock-free Single-Producer Single-Consumer (SPSC) circular queue.
* **49**: `drill_49_day038_concurrency_sharded_striped_mutex_hashmap.cpp` — Striped / sharded mutex concurrent hash map for multi-core throughput.
* **50**: `drill_50_day038_concurrency_thread_pool_pinned_workers.cpp` — Pinned thread worker pool (`pthread_setaffinity_np`) for zero cache-bouncing.
* **81**: `drill_81_day038_concurrency_data_race_vs_race_condition.cpp` — Data Race (UB) vs Race Condition (logical invariant violation).
* **82**: `drill_82_day038_concurrency_cas_weak_vs_strong.cpp` — Compare-And-Swap: `compare_exchange_weak` vs `compare_exchange_strong`.
* **83**: `drill_83_day038_concurrency_relaxed_counter_safety.cpp` — Safe monotonic counters with `std::memory_order_relaxed`.
* **84**: `drill_84_day038_concurrency_atomic_flag_wait_notify.cpp` — C++20 atomic notification via `std::atomic_flag::wait` and `notify_one`.
* **85**: `drill_85_day038_concurrency_lock_free_treiber_stack.cpp` — Lock-Free Treiber Stack with CAS.
* **86**: `drill_86_day038_concurrency_aba_problem_demonstration.cpp` — The ABA problem mechanics in lock-free stacks.
* **87**: `drill_87_day038_concurrency_tagged_pointer_aba_fix.cpp` — Tagged pointers: preventing ABA with version counters.
* **88**: `drill_88_day038_concurrency_writer_preference_rwlock.cpp` — Writer-preference read-write lock (starvation prevention).
* **89**: `drill_89_day038_concurrency_hazard_pointers_basics.cpp` — Hazard pointers: safe memory reclamation for lock-free reads.
* **90**: `drill_90_day038_concurrency_rcu_read_copy_update.cpp` — Read-Copy-Update (RCU) idiom for high-read vector indexes.
* **91**: `drill_91_day038_concurrency_concurrent_atomic_bitset.cpp` — Lock-free concurrent bitset via atomic `fetch_or`.
* **92**: `drill_92_day038_concurrency_thread_local_scratch_buffer.cpp` — `thread_local` storage: zero-allocation query scratchpads.
* **93**: `drill_93_day038_concurrency_work_stealing_deque_basics.cpp` — Work-stealing deque: local LIFO vs remote FIFO stealing.
* **94**: `drill_94_day038_concurrency_std_latch_sharded_sync.cpp` — Batch synchronization with C++20 `std::latch`.
* **95**: `drill_95_day038_concurrency_std_barrier_iterative_kmeans.cpp` — Multi-phase iteration synchronization with C++20 `std::barrier`.
* **96**: `drill_96_day038_concurrency_std_counting_semaphore_throttling.cpp` — Resource throttling via C++20 `std::counting_semaphore`.
* **97**: `drill_97_day038_concurrency_lock_hierarchy_ranking.cpp` — Hierarchical mutex: deadlock elimination by rank enforcement.
* **98**: `drill_98_day038_concurrency_double_checked_locking_acquire_release.cpp` — Double-checked locking pattern with acquire-release atomics.
* **99**: `drill_99_day038_concurrency_atomic_bitwise_operations.cpp` — Atomic bitwise read-modify-write (`fetch_and`, `fetch_or`, `fetch_xor`).
* **100**: `drill_100_day038_concurrency_production_thread_pool.cpp` — Production pinned vector search thread pool with work queues.
