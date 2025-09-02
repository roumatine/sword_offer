#include "..\head.h"

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> res; // 定义了一个最小堆,greater<int>比较器确保最小的元素总是在堆顶
        for (auto &a : nums)
        {
            res.push(a);
            if (res.size() > k)
            {
                res.pop();
            }
        }
        return res.top();
    }
};