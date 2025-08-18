#include "..\head.h"

// lc34.在排序数组中查找元素的第一个和最后一个数
// 暴力做法:遍历每个数询问是否是这个数直到找到，时间复杂度O(n)

// 取中间弱碰到偶数个数呢 (L + r) / 2 -->可能会有溢出问题
// [L, M - 1] <- [L , M] -> [M + 1 , R]
// 因此下一步 L <- M + 1 ,  R <- M - 1
// L-1一定是红色， R+1一定是蓝色

// 关键为 循环不变量： L-1 , R+1
// 根据循环不变量 R + 1 就是我们查找的答案，循环结束后 R + 1 = L ,同时答案也是L

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = low_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
        {
            return {-1, -1};
        }
        int end = low_bound(nums, target + 1) - 1;
        return {start, end};
    }

    int low_bound(vector<int> &nums, int target)
    { // 闭区间 [left, right]
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (right - left) >> 1; // left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1; // [left, mid - 1]
            }
            else
            {
                left = mid + 1; // [mid + 1, right]
            }
        }
        return left;
    }

    int low_bound_2(vector<int> &nums, int target)
    { // 闭区间 [left, right]
        int left = 0, right = nums.size();
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

    int low_bound_3(vector<int> &nums, int target)
    { // 开区间 (left, right)
        int left = -1, right = nums.size();
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

    // 库函数
    vector<int> searchRange_K2(vector<int> &nums, int target)
    {
        int start = ranges::lower_bound(nums, target) - nums.begin();
        if (start == nums.size() || nums[start] != target)
        {
            return {-1, -1};
        }
        int end = ranges::upper_bound(nums, target) - nums.begin() - 1;
        return {start, end};
    }
    vector<int> searchRange_K1(vector<int> &nums, int target)
    {
        auto [start, end] = ranges::equal_range(nums, target);
        if (start == end)
        {
            return {-1, -1};
        }
        return {(int)(start - nums.begin()), (int)(end - nums.begin() - 1)};
    }
};