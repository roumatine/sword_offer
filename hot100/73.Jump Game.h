#include "..\head.h"

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > x)
            {
                return false;
            }
            x = max(x, i + nums[i]);
        }
        return true;
    }

    bool canJump(vector<int> &nums)
    {
        int mx = 0;
        for (int i = 0; mx < nums.size() - 1; i++)
        {
            if (i > mx)
            {
                return false;
            }
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
};