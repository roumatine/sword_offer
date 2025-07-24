#include "..\..\head.h"

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        auto dfs = [&](this auto &&dfs, int i, int j) -> int
        {
            if (i < 0 || j < 0)
            {
                return INT_MAX;
            }
            if (i == 0 && j == 0)
            {
                return grid[i][j];
            }
            return min(dfs(i, j - 1), dfs(i - 1, 1)) + grid[i][j];
        };
        return dfs(grid.size() - 1, grid[0].size() - 1);
    }

    int minPathSum_1(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector memo(m, vector<int>(n, -1));
        auto dfs = [&](this auto &&dfs, int i, int j) -> int
        {
            if (i < 0 || j < 0)
            {
                return INT_MAX;
            }
            if (i == 0 && j == 0)
            {
                return grid[i][j];
            }
            int &res = memo[i][j];
            if (res != -1)
            {
                return res;
            }
            return res = min(dfs(i, j - 1), dfs(i - 1, j)) + grid[i][j];
        };
        return dfs(m - 1, n - 1);
    }

    int minPathSum_2(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector f(m + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    f[1][1] = grid[i][j];
                }
                else
                {
                    f[i + 1][j + 1] = min(f[i + 1][j], f[i][f + 1]) + grid[i][j];
                }
            }
        }
        return f[m][n];
    }
};
