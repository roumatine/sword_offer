#include "..\..\head.h"

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector memo(n, vector<array<int, 2>>(k + 1, {-1, -1}));
        auto dfs = [&](this auto &&dfs, int i, int j, bool hold)
        {
            if (j < 0)
            {
                return INT_MIN / 2;
            }
            if (i < 0)
            {
                return hold ? INT_MIN / 2 : 0;
            }
            int &res = memo[i][j][hold];
            if (res != -1)
            {
                return res;
            }
            if (hold)
            {
                return res = max(dfs(i - 1, j, true), dfs(i - 1, j - 1, false) - prices[i]);
            }
            return res = max(dfs(i - 1, j, false), dfs(i - 1, j, true) + prices[i]);
        };
        return dfs(n - 1, k, false);
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector f(n + 1, vector<array<int, 2>>(k + 2, {INT_MIN / 2, INT_MIN / 2}));
        for (int j = 1; j <= k + 1; j++)
        {
            f[0][j][0] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= k + 1; j++)
            {
                f[i + 1][j][0] = max(f[i][j][0], f[i][j][1] + prices[i]);
                f[i + 1][j][1] = max(f[i][j][1], f[i][j - 1][0] - prices[i]);
            }
        }
        return f[n][k + 1][0];
    }
};