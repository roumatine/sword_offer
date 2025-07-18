#include "..\..\head.h"

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> path;

        auto dfs = [&](this auto &&dfs, int i, int left)
        {
            if (left == 0)
            {
                ans.push_back(path);
                return;
            }
            if (i == candidates.size() || left < 0) // sort(candidates); left < canditates[i]
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
};

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates);
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto &&dfs, int i, int left)
        {
            if (left == 0)
            {
                ans.push_back(path);
                return 0;
            }
            for (int j = i; j < candidates.size() && candidates[j] <= left; j++)
            {
                path.push_back(candidates[j]);
                dfs(j, left - candidates[j]);
                path.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};