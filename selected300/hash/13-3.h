#include "..\..\head.h"

// class Solution {
// public:
// int lengthOfLongestSubstring(string s) {
//         unordered_set<char> unset;
//         int n = s.size();
//         int rk = -1;
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             if (i != 0) {
//                 unset.erase(s[i - 1]);
//             }
//             while (rk + 1 < n && !unset.count(s[rk + 1])) {
//                 unset.insert(s[rk + 1]);
//                 ++rk;
//             }
//             ans = max(ans, rk - i + 1);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        unordered_set<char> unset;
        unset.insert(s[0]);
        int maxLen = 0;
        int left = 0;
        int len = s.size();
        for (int i = 1; i < len; ++i) {
            while (unset.find(s[i]) != unset.end()) {
                unset.erase(s[left]);
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
            unset.insert(s[i]);
        }
        return maxLen;
    }
};