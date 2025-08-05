#include "..\head.h"

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n, 1);
        for (int i = 1; i < n; ++i)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        vector<int> suf(n, 1);
        for (int i = n - 2; i >= 0; --i)
        {
            suf[i] = suf[i + 1] * nums[i + 1];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = pre[i] * suf[i];
        }
        return ans;
    }

    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> suf(n);
        suf[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            suf[i] = suf[i + 1] * nums[i + 1];
        }

        int pre = 1;
        for (int i = 0; i < n; i++)
        { // 此时 pre 为 nums[0] 到 nums[i-1] 的乘积，直接乘到 suf[i] 中
            suf[i] *= pre;
            pre *= nums[i];
        }
        return suf;
    }
};