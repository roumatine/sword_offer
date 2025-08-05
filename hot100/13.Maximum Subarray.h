#include "..\head.h"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        int min_pre_sum = 0;
        int pre_sum = 0;
        for (int x : nums)
        {
            pre_sum += x;
            ans = max(ans, pre_sum - min_pre_sum);
            min_pre_sum = min(min_pre_sum, pre_sum);
        }
        return ans;
    }

    int maxSubArray(vector<int> &nums)
    {
        vector<int> f(nums.size());
        f[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            f[i] = max(f[i - 1], 0) + nums[i];
        }
        return ranges::max(f);
    }

    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        int f = 0;
        for (int x : nums)
        {
            f = max(f, 0) + x;
            ans = max(ans, f);
        }
        return ans;
    }
};