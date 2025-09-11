#include "..\head.h"

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int ans = 0;
        int cur_right = 0;
        int next_right = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            next_right = max(next_right, i + nums[i]);
            if (i == cur_right)
            {
                cur_right = next_right;
                ans++;
            }
        }
        return ans;
    }
};