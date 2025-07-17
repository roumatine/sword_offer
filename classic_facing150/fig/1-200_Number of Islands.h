#include "..\..\head.h"

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = gird.size();
        int n = grid[0].size();
        auto dfs = [&](this auto &&dfs, int i, int j) -> void
        {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
            {
                return;
            }
            grid[i][j] = '2';
            dfs(i, j - 1);
            dfs(i, j + 1);
            dfs(i - 1, j);
            dfs(i + 1, j);
        };
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (gird[i][j] == '1')
                {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};