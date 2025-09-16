#include "..\head.h"

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
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

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < m; i++)
            grid[i][0] = grid[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            grid[0][j] = grid[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};