#include "..\..\head.h"


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        subsetsCore(nums, res, tmp, 0);
        return res;
    }

    void subsetsCore(vector<int> &nums, vector<vector<int>> &res, vector<int> &tmp, int index) {
        res.push_back(tmp);
        for (int i = index; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            subsetsCore(nums, res, tmp, i + 1);
            tmp.pop_back();
        }
    }
};