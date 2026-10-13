// ==============================================================================
// 🥋 Drill: Striped / Sharded Mutex Concurrent Hash Map
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 6.3: Designing more complex lock-based data structures)
// - Herlihy & Shavit: The Art of Multiprocessor Programming (Ch 13: Concurrent Hashing)
//
// 🎯 CORE LESSON:
// 1. A single global mutex causes severe lock contention under high multi-threaded concurrency.
// 2. Lock striping partitions the keyspace across $K$ independent shards with dedicated mutexes.
// 3. Allows multiple threads to read and write different shards simultaneously.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_49_day038_concurrency_sharded_striped_mutex_hashmap.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <cassert>

template <typename K, typename V, size_t NumStripes = 16>
class StripedHashMap {
    struct Shard {
        mutable std::mutex mtx;
        std::unordered_map<K, V> map;
    };

public:
    void insert(const K& key, const V& val) {
        size_t idx = std::hash<K>{}(key) % NumStripes;
        std::lock_guard<std::mutex> lock(shards_[idx].mtx);
        shards_[idx].map[key] = val;
    }

    bool find(const K& key, V& out_val) const {
        size_t idx = std::hash<K>{}(key) % NumStripes;
        std::lock_guard<std::mutex> lock(shards_[idx].mtx);
        auto it = shards_[idx].map.find(key);
        if (it != shards_[idx].map.end()) {
            out_val = it->second;
            return true;
        }
        return false;
    }

private:
    Shard shards_[NumStripes];
};

int main() {
    std::cout << "--- Drill 49: Striped Mutex Concurrent Hash Map ---\n\n";

    StripedHashMap<int, int, 16> map;
    std::vector<std::thread> workers;

    for (int i = 0; i < 4; ++i) {
        workers.emplace_back([&, i] {
            for (int k = 0; k < 1000; ++k) {
                map.insert(i * 1000 + k, k);
            }
        });
    }

    for (auto& w : workers) w.join();

    int val = 0;
    assert(map.find(2500, val) && val == 500);

    std::cout << "Concurrent striped map verified across 4 worker threads.\n";
    std::cout << "\n✓ Drill 49 Passed: Striped mutex map operational!\n";
    return 0;
}
