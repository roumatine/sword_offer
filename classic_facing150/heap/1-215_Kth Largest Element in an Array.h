#include "..\..\head.h"

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> res;
        for (auto &a : nums)
        {
            res.push(a);
            if (res.size() > k)
                res.pop();
        }
        return res.top();
    }
};