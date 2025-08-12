#include "..\head.h"
// 303.Range Sum Query - Immutable 区域和检索 - 数组不可变
// 前缀和

class NumArray
{
    vector<int> vec;

public:
    NumArray(vector<int> &nums)
    {
        vec.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            vec[i + 1] = vec[i] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        return vec[right + 1] - vec[left];
    }
};

// 560. Subarray Sum ERquals K 和为K的子数组

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
        for (int x : s)
        {
            ans += unmp.contains(x - k) ? unmp[x - k] : 0; // if (s[j]=s[i]-k)
            unmp[x]++;
        }
        return ans;
    }

    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0, s = 0;
        unordered_map<int, int> cnt{{0, 1}}; // s[0]=0 单独统计
        for (int x : nums)
        {
            s += x;
            // 注意不要直接 += cnt[s-k]，如果 s-k 不存在，这会插入 s-k，消耗更多空间
            ans += cnt.contains(s - k) ? cnt[s - k] : 0;
            cnt[s]++;
        }
        return ans;
    }

    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0, s = 0;
        unordered_map<int, int> cnt;
        for (int x : nums)
        {
            cnt[s]++;
            s += x;
            // 注意不要直接 += cnt[s-k]，如果 s-k 不存在，这会插入 s-k，消耗更多空间
            ans += cnt.contains(s - k) ? cnt[s - k] : 0;
        }
        return ans;
    }
};