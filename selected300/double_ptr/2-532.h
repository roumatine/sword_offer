#include "..\..\head.h"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            auto it = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + k);
            if (it == nums.end()) {
                break;
            }
            if (*it == nums[i] + k) {
                ++ ans;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> visit;
        unordered_set<int> res;
        for (int num : nums) {
            if (visit.count(num - k)) {
                res.emplace(num - k);
            }
            if (visit.count(num + k)) {
                res.emplace(num);
            }
            visit.emplace(num);
        }
        return res.size();
    }
};