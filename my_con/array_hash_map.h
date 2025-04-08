#include "head.h"

struct Pair {
public:
    int key;
    string val;
    Pair(int key, string val) {
        this->key = key;
        this->val = val;
    }
};

class ArrayHashMap {
private:
    vector<Pair*> buckets;
public:
    ArrayHashMap() {
        buckets = vector<Pair*>(100);
    }
    ~ArrayHashMap() {
        for (const auto &bucket : buckets) {
            delete bucket;
        }
        buckets.clear();
    }
    int hashFunc(int key) {
        int index = key % 100; 
        return index;
    }
    string get(int key) {
        int index = hashFunc(key);
        Pair *pair = buckets[index];
        if (pair == nullptr) {
            return "";
        }
        return pair->val;
    }

    void put(int key, string val) {
        Pair *pair = new Pair(key, val);
        int index = hashFunc(key);
        buckets[index] = pair
    }

    void remove(int key) {
        int index = hashFunc(key);
        delete buckets[index];
        buckets[index] = nullptr;
    }

    vector<Pair*> pair_set() {
        vector<Pair*> pair_set;
        for (Pair *pair : buckets) {
            if (pair != nullptr) {
                pair_set.push_back(pair);
            }
        }
        return pair_set;
    }

    vector<int> key_set() {
        vector<int> key_set;
        for (Pair *pair : buckets) {
            if (pair != nullptr) {
                key_set.push_back(pair->key);
            }
        }
        return key_set;
    }

    vector<string> val_set() {
        vector<string> val_set;
        for (Pair *pair : buckets) {
            if (pair != nullptr) {
                val_set.push_back(pair->val);
            }
        }
        return val_set;
    }

    void print() {
        for (Pair *p : pair_set()) {
            cout << p->key << "-> " << p->val << endl;
        }
    }
};