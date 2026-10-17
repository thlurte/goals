// ==============================================================================
// 🥋 Drill 20 (Day 34.11): Multithreading Mastery — Striped / Sharded Concurrent Hash Map
//
// 📖 READING SOURCES:
// - Herlihy & Shavit: The Art of Multiprocessor Programming (Ch 13: Concurrent Hashing)
// - Doug Lea: Java ConcurrentHashMap Design & Lock Striping Architecture
//
// 🎯 CORE LESSON:
// 1. Lock Striping: Instead of 1 global mutex, partition buckets into $S$ independent shards (e.g. 64 shards).
// 2. High Concurrency: Threads accessing different keys hash to different shards and acquire distinct locks in parallel.
// 3. Cache Line Padding (`alignas(64)`): Ensure shard mutexes do not share cache lines to prevent False Sharing.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra -pthread drill_20_day034_concurrency_sharded_striped_hash_map.cpp -o drill20 && ./drill20
// ==============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <shared_mutex>
#include <thread>
#include <cassert>
#include <optional>
#include <cstdint>

template <typename Key, typename Value, size_t NumShards = 64>
class StripedHashMap {
    static_assert((NumShards & (NumShards - 1)) == 0, "NumShards must be a power of 2!");

    struct alignas(64) Shard {
        mutable std::shared_mutex mutex;
        std::unordered_map<Key, Value> table;
    };

public:
    StripedHashMap() : shards_(NumShards) {}

    // TODO 1: Implement thread-safe find with shared (reader) lock
    // 1. Calculate shard index: shard_idx = std::hash<Key>{}(key) & (NumShards - 1)
    // 2. Acquire std::shared_lock<std::shared_mutex> on shards_[shard_idx].mutex
    // 3. Look up key in shards_[shard_idx].table (return std::optional<Value>)
    std::optional<Value> find(const Key& key) const {
        // [YOUR CODE HERE]
        (void)key;
        return std::nullopt;
    }

    // TODO 2: Implement thread-safe insert_or_assign with unique (writer) lock
    // 1. Calculate shard index: shard_idx = std::hash<Key>{}(key) & (NumShards - 1)
    // 2. Acquire std::unique_lock<std::shared_mutex> on shards_[shard_idx].mutex
    // 3. Insert or assign key/value into shards_[shard_idx].table
    void insert(const Key& key, const Value& val) {
        // [YOUR CODE HERE]
        (void)key;
        (void)val;
    }

    [[nodiscard]] size_t size() const {
        size_t total = 0;
        for (size_t i = 0; i < NumShards; ++i) {
            std::shared_lock lock(shards_[i].mutex);
            total += shards_[i].table.size();
        }
        return total;
    }

private:
    std::vector<Shard> shards_;
};

int main() {
    std::cout << "--- Drill 20: Striped Concurrent Hash Map with Cache Padding ---\n\n";

    StripedHashMap<int, int, 64> map;
    constexpr int NUM_THREADS = 8;
    constexpr int KEYS_PER_THREAD = 10000;

    // Concurrent writers
    std::vector<std::thread> writers;
    for (int t = 0; t < NUM_THREADS; ++t) {
        writers.emplace_back([&map, t]() {
            for (int i = 0; i < KEYS_PER_THREAD; ++i) {
                map.insert(t * KEYS_PER_THREAD + i, (t * KEYS_PER_THREAD + i) * 2);
            }
        });
    }

    for (auto& t : writers) t.join();

    assert(map.size() == NUM_THREADS * KEYS_PER_THREAD);
    std::cout << "✓ Inserted " << map.size() << " keys concurrently across " << NUM_THREADS << " threads!\n";

    // Concurrent readers
    std::vector<std::thread> readers;
    for (int t = 0; t < NUM_THREADS; ++t) {
        readers.emplace_back([&map, t]() {
            for (int i = 0; i < KEYS_PER_THREAD; ++i) {
                int key = t * KEYS_PER_THREAD + i;
                auto res = map.find(key);
                assert(res.has_value() && res.value() == key * 2);
            }
        });
    }

    for (auto& t : readers) t.join();

    std::cout << "✓ Verified all " << map.size() << " keys concurrently without contention!\n";
    std::cout << "\n✓ Drill 20 Passed: Striped concurrent hash map verified!\n";
    return 0;
}
