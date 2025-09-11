#include "..\head.h"

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector memo(n, vector<int>(amount + 1, -1));

        auto dfs = [&](this auto &&dfs, int i, int c) -> int
        {
            if (i < 0)
            {
                return c == 0 ? 0 : INT_MAX / 2;
            }
            int &res = memo[i][c];
            if (res != -1)
            {
                return res;
            }
            if (c < coins[i])
            {
                return res = dfs(i - 1, c);
            }
            return res = min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1);
        };
        int ans = dfs(n - 1, amount);
        return ans < INT_MAX / 2 ? ans : -1;
    }
    // 递推
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector f(n + 1, vector<int>(amount + 1, INT_MAX / 2));
        f[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int c = 0; i <= amount; c++)
            {
                if (c < coins[i])
                {
                    f[i + 1][c] = f[i][c];
                }
                else
                {
                    f[i + 1][c] = min(f[i][c], f[i + 1][c - coins[i]] + 1);
                }
            }
        }
        int ans = f[n][amount];
        return ans < INT_MAX / 2 ? ans : -1;
    }
    // 空间优化
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> f(amount + 1, INT_MAX / 2);
        f[0] = 0;
        for (int x : coins)
        {
            for (int c = x; c <= amount; c++)
            {
                f[c] = min(f[c], f[c - x] + 1);
            }
        }
        int ans = f[amount];
        return ans < INT_MAX / 2 ? ans : -1;
    }
};