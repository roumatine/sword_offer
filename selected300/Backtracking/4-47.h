#include "..\..\head.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        permuteUniqueCore(nums, res, 0);
        return res;
    }

    vector<vector<int>> permuteUniqueCore(vector<int> &nums, vector<vector<int>> &res, int index) {
        if (index == nums.size())
            res.push_back(nums);
        else {
            unordered_map<int, int> unmp;
            for (int i = index; i < nums.size(); i++) {
                if (unmp.count(nums[i]))
                    continue;
                swap(nums[index], nums[i]);
                permuteUniqueCore(nums, res, index + 1);
                swap(nums[index], nums[i]);
                unmp[nums[i]] ++;
            }
        }
    }
};