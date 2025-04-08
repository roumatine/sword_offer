#include "..\head.h"#
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

    
};