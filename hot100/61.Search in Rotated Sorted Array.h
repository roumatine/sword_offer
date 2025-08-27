#include "..\head.h"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int i = findMin(nums);
        if (target > nums.back())
        {
            return lower_bound(nums, -1, i, target);
        }
        return lower_bound(nums, i - 1, nums.size(), target);
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
        if (nums[right] != target)
        {
            return -1;
        }
        return right;
    }
    int findMin(vector<int> &nums)
    {
        int left = -1;
        int right = nums.size() - 1;
        while (left + 1 < right)
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

    int search_once(vector<int> &nums, int target)
    {
        int last = nums.back();
        int left = -1;
        int right = nums.size() - 1;
        while (left + 1 < right)
        {
            int mid = left + ((right - left) >> 1);
            int x = nums[mid];
            if (target > last && x <= last)
            {
                right = mid;
            }
            else if (x > last && target <= last)
            {
                left = mid;
            }
            else if (x >= target)
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