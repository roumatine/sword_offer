#include "..\..\head.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0)
            return vector<vector<int>>();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    void dfs(vector<int> nums, int x) {
        if (x == nums.size() - 1)
            res.push_back(nums);
            return;
        for (int i = x; i < nums.size(); i++) {
            swap(nums[x], nums[i]);
            dfs(nums, x + 1);
            swap(nums[i], nums[x]);
        }
    }
};