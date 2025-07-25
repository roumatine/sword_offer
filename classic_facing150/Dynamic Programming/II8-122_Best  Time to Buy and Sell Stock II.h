#include "..\..\head.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            if (i - 1 == -1)
            {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<array<int, 2>> memo(n, {-1, 1});
        auto dfs = [&](this auto &&dfs, int i, bool hold) -> int
        {
            if (i < 0)
            {
                return hold ? INT_MIN : 0;
            }
            int &res = memo[i][hold];
            if (res != -1)
            {
                return res;
            }
            if (hold)
            {
                return res = max(dfs(i - 1, true), dfs(i - 1, false) - prices[i]);
            }
            return res = max(dfs(i - 1, false), dfs(i - 1, true) + prices[i]);
        };
        return dfs(n - 1, false);
    }
};