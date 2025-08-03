#include "..\head.h"

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> pre_max(n);
        pre_max[0] = height[0];
        for (int i = 1; i < n; ++i)
        {
            pre_max[i] = max(pre_max[i - 1], height[i]);
        }
        vector<int> sur_max(n);
        sur_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            sur_max[i] = max(sur_max[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += min(pre_max[i], sur_max[i]) - height[i]; // 累加 能接水的量（水桶容量- 高度）
        }
        return ans;
    }

    int trap1(vector<int> &height)
    {
        int n = height.size();
        int ans = 0, pre_max = 0, sur_max = 0;
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            pre_max = max(pre_max, height[left]);
            sur_max = max(sur_max, height[right]);
            if (pre_max < sur_max) // ans += pre_max < suf_max ? pre_max - height[left++] : suf_max - height[right--];
            {
                ans += pre_max - height[left];
                left++;
            }
            else
            {
                ans += sur_max - height[right];
                right--;
            }
        }
        return ans;
    }
};