#include "..\head.h"
// 46.全排列
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path(n);
        vector<int> on_path(n);

        auto dfs = [&](this auto &&dfs, int i)
        {
            if (i == n)
            {
                ans.push_back(path);
                return;
            }
            for (int j = 0; j < n; j++)
            {
                if (!on_path[j])
                {
                    path[i] = path[j];
                    on_path[j] = true;
                    dfs(i + 1);
                    on_path[j] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};