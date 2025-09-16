#include "..\head.h"

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n);

        auto dfs = [&](this auto &&dfs, int i) -> int
        {
            int &res = memo[i];
            if (res > 0)
            {
                return res;
            }

            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    res = max(res, dfs(j));
                }
            }
            res++;
            return res;
        };

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dfs(i));
        }
        return ans;
    }

    // 递推
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> f(n);
        for (int i = 0; i < n; i++)
        {
            f[i] = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i]++;
        }
        return ranges::max(f);
    }
};