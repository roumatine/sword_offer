#include "..\..\head.h"

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int x : nums)
        {
            ans += cnt[x]; // 每当遇到一个数字x时，当前x之前出现的次数cnt[x]就是能与当前x形成好数对的数量
            cnt[x]++;
        }
        return ans;
    }

    int numIdenticalPairs(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] == nums[j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};