#include "..\..\head.h"

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    { // 开区间 (-1, n-1)
        int left = -1;
        int right = nums.size() - 1;
        while (left + 1 < right)
        { // 开区间不为空
            int mid = ((right - left) >> 1) + left;
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return right;
    }
};