#include "..\head.h"

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();

        auto dfs = [&](this auto &&dfs, int i, int left)
        {
            if (left == 0)
            {
                ans.push_back(path);
                return;
            }
            if (i == n || left < 0)
            {
                return;
            }
            dfs(i + 1, left);

            path.push_back(candidates[i]);
            dfs(i, left - candidates[i]);
            path.pop_back();
        };
        dfs(0, target);
        return ans;
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        ranges::sort(candidates);
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto &&dfs, int i, int left)
        {
            if (left == 0)
            {
                ans.push_back(path);
                return;
            }
            if (i == n || left < candidates[i])
            {
                return;
            }

            dfs(i + 1, left);

            path.push_back(candidates[i]);
            dfs(i, left - candidates[i]);
            path.pop_back();
        };
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        ranges::sort(candidates);
        vector<vector<int>> ans;
        vector<int> path;

        auto dfs = [&](this auto &&dfs, int i, int left)
        {
            if (left == 0)
            {
                // 找到一个合法组合
                ans.push_back(path);
                return;
            }

            // 枚举选哪个
            for (int j = i; j < candidates.size() && candidates[j] <= left; j++)
            {
                path.push_back(candidates[j]);
                dfs(j, left - candidates[j]);
                path.pop_back(); // 恢复现场
            }
        };

        dfs(0, target);
        return ans;
    }
};