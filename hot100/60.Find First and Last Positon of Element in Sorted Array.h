#include "..\head.h"
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
        {
            return {-1, -1};
        }
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }

    int lower_bound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    int lower_bound_1(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    int lower_bound_2(vector<int> &nums, int target)
    {
        int left = -1;
        int right = nums.size();
        while (left + 1 < right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target)
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