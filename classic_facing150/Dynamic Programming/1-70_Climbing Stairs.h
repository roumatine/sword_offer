#include "..\..\head.h"

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> res(n + 1, 0);
        res[1] = 1;
        res[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n];
    }
};

class Solution
{
    vector<int> memo;

    int dfs(int i)
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
    }

public:
    int climbStairs(int n)
    {
        memo.resize(n + 1);
        return dfs(n);
    }
    int climbStairs_1(int n)
    {
        vector<int> f(n + 1);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};