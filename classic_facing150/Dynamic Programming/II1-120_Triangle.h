#include "..\..\head.h"

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector memo(n, vector<int>(n, INT_MIN));

        auto dfs = [&](this auto &&dfs, int i, int j) -> int
        {
            if (i == n - 1)
            {
                return triangle[i][j];
            }
            int &res = memo[i][j];
            if (res != INT_MIN)
            {
                return res;
            }
            return res = min(dfs(i + 1, j), dfs(i + 1, j + 1));
        };
        return dfs(0, 0);
    }

    int minimumTotal_1(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector f(n, vector<int>(n));
        f[n - 1] = triangle[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return f[0][0];
    }

    int minimumTotal(vector<vector<int>> &f)
    {
        for (int i = f.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                f[i][j] += min(f[i + 1][j], f[i + 1][j + 1]);
            }
        }
        return f[0][0];
    }
};