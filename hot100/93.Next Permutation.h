#include "..\head.h"

// 下一个排序                                   下一个整数                      相同点
// 从右向左，找到第一个小于右侧向来是数字的x        从右向左找到第一个小于9的数x    都是找到第一个小于右侧相邻数字的数
// 找x右边最小的大于x的数字y，交换x和y              把x+1，得到y=x+1                增大这个数
// 反转y右侧的数，把右边的数变成最小的排列          把y右边的数都变成最小的个位数   把右边的数字变成最小
// 123
// 132
// 231
// 321

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }

        if (i >= 0)
        {
            int j = n - 1;
            while (nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }

    void nextPermutation(vector<int> &nums)
    {
        ranges::next_permutation(nums);
    }
};