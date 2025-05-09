#include "..\..\head.h"

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> unmp;
        int res = 0;
        for (int num : nums) {
            unmp[num] ++;
        }
        for (auto [key, val] : unmp) {
            if (unmp.count(key + 1)) {
                res = max(res, val + unmp[key + 1]);
            }
        }
        return res;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int begin = 0;
        int res = 0;
        for (int end = 0; end < nums.size(); ++ end) {
            while (nums[end] - nums[begin] > 1) {
                begin ++;
            }
            if (nums[end] - nums[begin] == 1) {
                res = max(res, end - begin + 1);
            }
        }
        return res;
    }
};