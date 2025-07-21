#include "..\..\head.h"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 两次二分
        int i = findMin(nums);
        if (target > nums.back()) // target 在第一段
        {
            return lower_bound(nums, -1, i, target); // 开区间 (-1, i)
        }
        return lower_bound(nums, i - 1, nums.size(), target); // 开区间 (i-1, n)
    }

private:
    int findMin(vector<int> &nums)
    {
        int left = -1;
        int right = nums.size() - 1;
        while (left + 1 < right)
        // 这个条件确保当left和right相邻时循环终止
        // 这种写法避免了常见的二分查找中的边界问题（如无限循环）
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < nums.back())
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

    int lower_bound(vector<int> &nums, int left, int right, int target)
    {
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
        return nums[right] == target ? right : -1;
    }
};

class Solution
{ // 一次二分
public:
    int search(vector<int> &nums, int target)
    {
        int end = nums.back();
        auto check = [&](int i) -> bool
        {
            int x = nums[i];
            if (x > end)
            {
                return target > end && x >= target;
            }
            return target > end || x >= target;
        };
        int left = -1;
        int right = nums.size() - 1;
        while (left + 1 < right)
        {
            int mid = left + ((right - left) >> 1);
            (check(mid) ? right : left) = mid;
        }
        return nums[right] == target ? right : -1;
    }
};