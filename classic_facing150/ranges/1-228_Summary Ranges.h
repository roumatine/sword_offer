#include "..\..\head.h"

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        auto f = [&](int i, int j)
        {
            return i == j ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[j]);
        };

        for (int i = 0, j, n = nums.size(); i < n; i = j + 1)
        {
            j = i;
            while (j + 1 < n && nums[j + 1] == nums[j] + 1)
            {
                ++j;
            }
            res.emplace_back(f(i, j));
        }
        return res;
    }
};

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            int start = nums[i++];
            while (i < n && nums[i] == nums[i - 1] + 1)
            {
                i++;
            }
            int end = nums[i - 1];
            string strs = to_string(start);
            if (end != start)
            {
                strs += "->" + to_string(end);
            }
            res.push_back(strs);
        }
        return res;
    }
};