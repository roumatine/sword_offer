#include "..\..\head.h"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = nums[0];
        int sum = 0;
        for (auto a : nums)
        {
            if (sum + a > a)
            {
                sum += a;
            }
            else
            {
                sum = a;
            }
            result = sum > result ? sum : result; // max(sum, result)
        }
        return result;
    }
};

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
};

class Solution
{
public:
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
    int maxSubarray_1(vector<int> &nums)
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