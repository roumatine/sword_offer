#include "..\head.h"

class Solution
{
public:
    void moveZeroes_stk(vector<int> &nums)
    {
        int stk_size = 0;
        for (int n : nums)
        {
            if (n)
            {
                nums[stk_size++] = n;
            }
        }
        fill(nums.begin() + stk_size, nums.end(), 0);
    }
};

class Solution
{
public:
    void moveZeroes_1(vector<int> &nums)
    {
        int i0 = 0;
        for (int &x : nums)
        {
            if (x)
            {
                swap(x, nums[i0]);
                i0++;
            }
        }
    }
};

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int fast = 0;
        int slow = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
    void moveZeroes(vector<int> &nums)
    {
        int p = removeElement(nums, 0);
        for (; p < nums.size(); p++)
        {
            nums[p] = 0;
        }
    }
};