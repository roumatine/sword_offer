#include "..\..\head.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        subsetsWithDupCore(nums, res, tmp, 0);
        return res;
    }
    
    void subsetsWithDupCore(vector<int> &nums, vector<vector<int>> &res, vector<int> &tmp, int index) {
        res.push_back(tmp);
        unordered_map<int, int> unmp;
        for (int i = index; i < nums.size(); i++) {
            if (unmp[nums[i]] > 0)
                continue;
            tmp.push_back(nums[i]);
            subsetsWithDupCore(nums, res, tmp, i + 1);
            tmp.pop_back();
            unmp[nums[i]]++;
        }
    }
};