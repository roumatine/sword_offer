#include "..\..\head.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;

        for (int num : s) {
            if (s.find(num - 1) != s.end()) { // s.contains(x - 1)
                // num 不是连续子序列的第一个，跳过
                continue;
            }
            int Nums = num + 1;
            while (s.find(Nums + 1) != s.end()) { // s.contains(Num)
                Nums++;
            }
            res = max(res, Nums - num);
        }
        return res;
    }
};