#include "..\head.h"

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int p0 = 0;
        int p1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            nums[i] = 2;
            if (x <= 1)
            {
                nums[p1++] = 1;
            }
            if (x == 0)
            {
                nums[p0++] = 0;
            }
        }
    }

    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[ptr], nums[i]);
                ++ptr;
            }
        }
        for (int i = ptr; i < n; i++)
        {
            if (nums[i] == 1)
            {
                swap(nums[ptr], nums[i]);
                ++ptr;
            }
        }
    }

    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int index = -1;
        while (low <= high)
        {
            if (nums[low] == 0)
            {
                swap(nums[++index], nums[low++]);
            }
            else if (nums[low] == 2)
            {
                swap(nums[high--], nums[low]);
            }
            else
            {
                low++;
            }
        }
    }
};