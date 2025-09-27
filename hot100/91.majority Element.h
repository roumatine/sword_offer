#include "..\head.h"

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ans = 0;
        int cnt = 0;
        for (int num : nums)
        {
            if (cnt == 0)
            {
                ans = num;
                cnt = 1;
            }
            else
            {
                cnt += num == ans ? 1 : -1;
            }
        }
        return ans;
    }
    int majorityElement(vector<int> &nums)
    {
        int target = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                target = nums[i];
                cnt = 1;
            }
            else if (nums[i] == target)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return target;
    }

    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> unmp;
        int maxCount = 0;
        int maxNum;
        for (int num : nums)
        {
            unmp[num]++;
            if (unmp[num] > maxCount)
            {
                maxCount = unmp[num];
                maxNum = num;
            }
        }
        return maxNum;
    }
};