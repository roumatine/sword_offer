#include "..\..\head.h"

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int max_s = INT_MIN;
        int min_s = 0;
        int max_f = 0;
        int min_f = 0;
        int sum = 0;
        for (int x : nums)
        {
            max_f = max(max_f, 0) + x;
            max_s = max(max_s, max_f);

            min_f = min(min_f, 0) + x;
            min_s = min(min_s, min_f);
            sum += x;
        }
        return sum == min_s ? max_s : max(max_s, sum - min_s);
    }
};