#include "..\head.h"
#include "Backtracking.h"

class Solution
// 78.子集 ->每个元素选或不选
// 1. 当前操作 枚举第i个数，选或者不选
// 2. 子问题 从下表>=i 的数字重构造子集
// 3. 下一个子问题 从下标>=i+1的数字中构造子集
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        auto dfs = [&](this auto &&dfs, int i)
        {
            if (i == n)
            {
                ans.push_back(path);
                return;
            }
            // 不选
            dfs(i + 1);

            // 选 nums[i]
            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back();
        };
        dfs(0);
        return ans;
    }

    vector<vector<int>> subsets(vector<int> &nums) // 选
    {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        auto dfs = [&](this auto &&dfs, int i)
        {
            ans.push_back(path);

            if (i == n)
            {
                return;
            }
            for (int j = i; j < n; j++)
            {
                path.push_back(nums[j]);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};