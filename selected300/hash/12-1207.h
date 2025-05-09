#include "..\..\head.h"
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> unmp;
        for (const auto& a : arr) {
            unmp[a] ++;
        }
        unordered_set<int> unset;
        for (const auto& a : unmp) {
            unset.insert(a.second);
        }
        return unmp.size() == unset.size();
    }
};