#include "..\..\head.h"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n, -1);
        auto dfs = [&](this auto &&dfs, int i) ->
        {
            if (i < 0)
            {
                return 0;
            }
            if (memo[i] != -1)
            {
                return memo[i];
            }
            return memo[i] = max(dfs(i - 1), dfs(i - 2) + nums[i]);
        };
        return dfs(n - 1);
    }

    int rob1(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> f(n + 2);
        for (int i = 0; i < n; ++i)
        {
            f[i + 2] = max(f[i + 1], f[i] + nums[i]);
        }
        return f[n + 1];
    }

    int rob2(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];
        else if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> res(n + 1, 0);
        res[1] = nums[0];
        res[2] = nums[1];
        for (int i = 2; i < n; ++i)
        {
            res[i + 1] = max(res[i - 1], res[i - 2]) + nums[i];
        }
        return max(res[n], res[n - 1]);
    }
};