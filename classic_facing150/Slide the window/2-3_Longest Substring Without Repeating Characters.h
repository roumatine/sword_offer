#include "..\..\head.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0, left = 0;
        unordered_map<char, int> unmp;
        for (int right = 0; right < n; right++) {
            char c = s[right];
            unmp[c]++;
            while (unmp[c] > 1) {
                unmp[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};