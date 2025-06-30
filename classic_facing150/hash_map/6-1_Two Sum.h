#include "..\..\head.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> unmp;
        for (int i = 0; i < nums.size(); ++i) {
            int n = target - nums[i];
            if (unmp.find(n) != unmp.end()) {
                return {unmp[n], i};
            }
            unmp[nums[i]] = i;
        }
        return{};
    }
};