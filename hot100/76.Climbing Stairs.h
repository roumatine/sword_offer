#include "..\head.h"

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> memo;
        auto dfs = [&](this auto &&dfs, int i) -> int
        {
            if (i <= 1)
            {
                return 1;
            }
            int &res = memo[i];
            if (res)
            {
                return res;
            }
            return res = dfs(i - 1) + dfs(i - 2);
        };
        memo.resize(n + 1);
        return dfs(n);
    }

    int climbStairs(int n)
    {
        vector<int> f(n + 1);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
    // 空间优化
    int climbStairs(int n)
    {
        int f0 = 1;
        int f1 = 1;
        for (int i = 2; i <= n; i++)
        {
            int new_f = f1 + f0;
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};