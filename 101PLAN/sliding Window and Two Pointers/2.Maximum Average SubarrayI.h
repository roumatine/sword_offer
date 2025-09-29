#include "..\..\head.h"

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int max_n = INT_MIN;
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += nums[i];
            // int left = i - k + 1
            if (i < k - 1)
            { // left < 0;
                continue;
            }
            max_n = max(max_n, s);
            s -= nums[i - k + 1];
        }
        return (double)max_n / k;
    }
};