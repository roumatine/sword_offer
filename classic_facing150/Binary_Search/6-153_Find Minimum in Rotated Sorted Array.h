#include "..\..\head.h"

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = -1;
        int right = nums.size() - 1;
        while (left + 1 < right)
        {
            int mid = ((right - left) >> 1) + left;
            (nums[mid] < nums.back() ? right : left) = mid;
        }
        return nums[right];
    }
};