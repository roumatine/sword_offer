#include "..\head.h"
#include "array_hash_map.h"

class HashMapChaining {
private:
    int size;
    int capacity;
    double loadThres;
    int extendRatio;
    vector<vector<Pair *>> buckets;

public:
    HashMapChaining() : size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2) {
        buckets.resize(capacity);
    }
    ~HashMapChaining() {
        for (auto &bucket : buckets) {
            for (Pair *pair : bucket) {
                delete pair;
            }
        }
    }
    int hashFunc(int key) {
        return key % capacity;
    }
    double loadFactor() {
        return (double) size / (double)capacity;
    }
    string get(int key) {
        int index = hashFunc(key);
        for (Pair *pair : buckets[index]) {
            if (pair->key == key) {
                return pair->val;
            }
        }
        return "";
    }
    void put(int key, string val) {
        // 当负载因子超过阈值时，执行扩容
        if (loadFactor() > loadThres) {
            extend();
        }
        int index = hashFunc(key);
        // 遍历桶，若遇到指定 key ，则更新对应 val 并返回
        for (Pair *pair : buckets[index]) {
            if (pair->key == key) {
                pair->val = val;
                return;
            }
        }
        // 若无该 key ，则将键值对添加至尾部
        buckets[index].push_back(new Pair(key, val));
        size++;
    }
    void remove(int key) {
        int index = hashFunc(key);
        auto &bucket = buckets[index];
        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i]->key == key) {
                Pair *tmp = bucket[i];
                bucket.erase(bucket.begin() + i);
                delete tmp;
                size--;
                return;
            }
        }
    }
    void extend() {
        // 暂存原哈希表
        vector<vector<Pair *>> bucketsTmp = buckets;
        // 初始化扩容后的新哈希表
        capacity *= extendRatio;
        buckets.clear();
        buckets.resize(capacity);
        size = 0;
        // 将键值对从原哈希表搬运至新哈希表
        for (auto &bucket : bucketsTmp) {
            for (Pair *pair : bucket) {
                put(pair->key, pair->val);
                // 释放内存
                delete pair;
            }
        }
    }
    void print() {
        for (auto &bucket : buckets) {
            cout << "[";
            for (Pair *pair : bucket) {
                cout << pair->key << " -> " << pair->val << ", ";
            }
            cout << "]\n";
        }
    }
};