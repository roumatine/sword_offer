#include "..\head.h"

class Solution
{ // 暴力写法
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0;; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
    vector<int> twoSum(vector<int> &nums, int target)
    { // 哈希表
        unordered_map<int, int> unmp;
        for (int j = 0;; j++)
        {
            // 在左边找 nums[i]，满足 nums[i]+nums[j]=target
            auto it = unmp.find(target - nums[j]);
            if (it != unmp.end())
            {
                return {it->second, j};
            }
            unmp[nums[j]] = j;
        }
    }
};
