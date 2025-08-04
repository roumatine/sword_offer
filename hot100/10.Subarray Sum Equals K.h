#include "..\head.h"

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++)
        {
            s[i + 1] = s[i] + nums[i];
        }

        int ans = 0;
        unordered_map<int, int> unmp;
        for (int a : s)
        {
            ans += unmp.contains(a - k) ? unmp[a - k] : 0;
        }
        return ans;
    }

    int subarraySum_1(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        int s = 0;
        unordered_map<int, int> cnt{{1, 0}};
        for (int x : nums)
        {
            s += x;
            ans += cnt.contains(s - k) ? cnt[s - k] : 0;
            cnt[s]++;
        }
        return ans;
    }
    int subarraySum_11(vector<int> &nums, int k)
    {
        int ans = 0;
        int s = 0;
        unordered_map<int, int> cnt;
        for (int x : nums)
        {
            cnt[s]++;
            s += x;
            ans += cnt.contains(s - k) ? cnt[s - k] : 0;
        }
        return ans;
    }
};