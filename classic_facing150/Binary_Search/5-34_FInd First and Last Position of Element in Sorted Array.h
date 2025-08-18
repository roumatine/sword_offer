#include "..\..\head.h"

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

private:
    // 闭区间写法
    int lower_bound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (right - left) >> 1;
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

    // 左闭右开区间写法
    int lower_bound1(vector<int> &nums, int target)
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

    //  开区间写法
    int lower_bound2(vector<int> &nums, int target)
    {
        int left = -1;
        int right = nums.size();
        while (left + 1 < right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) // (nums[mid] >= target ? right : left = mid)
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
