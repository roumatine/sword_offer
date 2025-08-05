#include "..\head.h"

class Solution
{
public:
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();

        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();

        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    void rotate(vector<int> &nums, int k)
    {
        auto reverse = [&](int i, int j)
        {
            while (i < j)
            {
                swap(nums[i++], nums[j--]);
            }
        };

        int n = nums.size();
        k %= nums.size();
        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
    }

    // void rotate(vector<int> &nums, int k)
    // {
    //     k %= nums.size();
    //     ranges::reverse(nums);
    //     reverse(nums.begin(), nums.begin() + k);
    //     reverse(nums.begin() + k, nums.end());
    // }
};