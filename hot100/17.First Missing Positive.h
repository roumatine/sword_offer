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
                int j = nums[i] - 1;
                swap(nums[i], nums[j]); // swp(nums[i], nums[nums[i - 1]]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};