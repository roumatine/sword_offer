#include "..\..\head.h"

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> unmp;
        for (char ch : s) {
            ++unmp[ch];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (unmp[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};