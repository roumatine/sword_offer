#include "..\..\head.h"

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> unmp;
        int cut = 0;
        int minNum = 0;
        int maxNum = 0;
        for (auto &a : dominoes) {
            maxNum = max(a[0], a[1]);
            minNum = min(a[0], a[1]);
            if (unmp.find(minNum * 10 + maxNum) != unmp.end()) {
                cut += unmp[minNum * 10 + maxNum];
            }
            unmp[minNum * 10 + maxNum] += 1;
        }
        return cut;
    }
};



class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> num;
        int ret = 0;
        for (auto &a : dominoes) {
            int val = a[0] < a[1] ? a[0] * 10 + a[1] : a[1] * 10 + a[0];
            ret += num[val];
            num[val] ++;
        }
        return ret;
    }
};