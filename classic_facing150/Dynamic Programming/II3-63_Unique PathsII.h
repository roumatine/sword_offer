#include "..\..\head.h"

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector memo(m, vector<int>(n, -1));
        auto dfs = [&](this auto &&dfs, int i, int j) -> int
        {
            if (i < 0 || j < 0 || obstacleGrid[i][j])
            {
                return 0;
            }
            if (i == 0 && j == 0)
            {
                return 1;
            }
            int &res = memo[i][j];
            if (res != -1)
            {
                return res;
            }
            return res = dfs(i - 1, j) + dfs(i, j - 1);
        };
        return dfs(m - 1, n - 1);
    }

    int uniquePathsWithObstacles_1(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector f(m + 1, vector<int>(n + 1));
        f[0][1] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    f[i + 1][j + 1] = f[i][j + 1] + f[i + 1][j];
                }
            }
        }
        return f[m][n];
    }

    int uniquePathsWithObstacles_space(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid[0].size();
        vector<int> f(n + 1);
        f[1] = 1;
        for (auto &row : obstacleGrid)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[j] == 0)
                {
                    f[j + 1] += f[j];
                }
                else
                {
                    f[j + 1] = 0;
                }
            }
        }
        return f[n];
    }
};