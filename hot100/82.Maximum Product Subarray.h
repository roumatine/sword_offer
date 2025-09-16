#include "..\head.h"

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = INT_MIN;
        int f_max = 1;
        int f_min = 1;
        for (int x : nums)
        {
            int mx = f_max;
            f_max = max({f_max * x, f_min * x, x});
            f_min = min({mx * x, f_min * x, x});
            ans = max(ans, f_max);
        }
        return ans;
    }

    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> fmax(n), fmin(n);
        fmax[0] = fmin[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int x = nums[i];
            fmax[i] = max({fmax[i - 1] * x, fmin[i - 1] * x, x});
            fmin[i] = min({fmax[i - 1] * x, fmin[i - 1] * x, x});
        }
        return ranges::max(fmax);
    }
};