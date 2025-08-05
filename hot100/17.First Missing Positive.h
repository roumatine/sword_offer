#include "..\head.h"

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            while (1 <= nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                int j = nums[i] - 1;    // 计算当前数字的正确位置。
                swap(nums[i], nums[j]); // swp(nums[i], nums[nums[i - 1]]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            } // 如果所有位置都满足条件（即数组中包含 [1, n]，那么缺失的最小正整数是 `n + 1）
        }
        return n + 1;
    }
};