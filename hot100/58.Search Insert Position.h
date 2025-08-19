#include "..\head.h"

class Solution
{
public:
    int low_bound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }

    int searchInsert(vector<int> &nums, int target)
    {
        return low_bound(nums, target);
    }
};