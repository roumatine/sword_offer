#include "..\head.h"

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int s = reduce(nums.begin(), nums.end());
        if (s % 2)
        {
            return false;
        }

        int n = nums.size();
        vector memo(n, vector<int>(s / 2 + 1, -1));

        auto dfs = [&](this auto &&dfs, int i, int j) -> bool
        {
            if (i < 0)
            {
                return j == 0;
            }
            int &res = memo[i][j];
            if (res != -1)
            {
                return res;
            }
            if (j < nums[i])
            {
                return res = dfs(i - 1, j);
            }
            return res = dfs(i - 1, j - nums[i] || dfs(i - 1, j));
        };
        return dfs(n - 1, s / 2);
    }

    bool canPartition(vector<int> &nums)
    {
        int s = reduce(nums.begin(), nums.end());
        if (s % 2)
        {
            return false;
        }
        s /= 2;
        int n = nums.size();
        vector f(n + 1, vector<int>(s + 1));
        f[0][0] = true;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            for (int j = 0; j <= s; j++)
            {
                f[i + 1][j] = j >= x && f[i][j - x] || f[i][j];
            }
        }
        return f[n][s];
    }

    bool canPartition(vector<int> &nums)
    {
        int s = reduce(nums.begin(), nums.end());
        if (s % 2)
        {
            return false;
        }
        s /= 2;
        bitset<10001> f;
        f[0] = 1;
        for (int x : nums)
        {
            f |= f << x;
        }
        return f[s];
    }
};