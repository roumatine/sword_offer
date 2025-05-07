#include "..\..\head.h"

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> unmp;
        for (auto &num :deck) {
            unmp[num]++;
        }
        int gcd = unmp.begin()->second;
        for (auto &iter : unmp) {
            gcd = gcd(iter.second,gcd);
        }
    }
    return gcd >= 2;
};