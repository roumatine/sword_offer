#include "..\..\head.h"

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return ranges::lower_bound(nums, target) - nums.begin();
    }
};

class Solution2
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(nums, target);
    }

private:
    int lower_bound(vector<int> &nums, int target)
    { // 闭区间写法[left, right]
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2; // ((right - left) >> 1);
            if (nums[mid] < target)
            {
                left = mid + 1; // 范围缩小到 [mid+1, right]
            }
            else
            {
                right = mid - 1; // 范围缩小到 [left, mid-1]
            }
        }
        return left;
    }

    int lower_bound2(vector<int> &nums, int target)
    { // 左闭右开区间写法[left, right)
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
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

    int lower_bound3(vector<int> &nums, int target)
    {
        // 开区间写法 (left, right)
        int left = -1;
        int right = nums.size();
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return right;
    }
};