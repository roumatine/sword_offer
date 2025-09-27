#include "..\head.h"

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int left = 1;
        int right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int num : nums)
            {
                if (num <= mid)
                {
                    cnt++;
                }
            }
            if (cnt > mid)
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

    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};