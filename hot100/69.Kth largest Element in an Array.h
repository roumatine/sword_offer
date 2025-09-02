#include "..\head.h"

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }

    int findKthLargest_k(vector<int> &nums, int k)
    {                                                       // Top-K 问题，小顶堆，维护 k 个元素
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

    int findKthLargest_b(vector<int> &nums, int k)
    { // 大顶堆
        priority_queue<int, vector<int>> max_heap;
        for (int x : nums)
        {
            max_heap.push(x);
        }
        for (int i = 0; i < k - 1; i++)
        {
            max_heap.pop();
        }
        return max_heap.top();
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int x : nums)
        {
            min_heap.push(x);
        }
        for (int i = 0; i < nums.size() - k; i++)
        {
            min_heap.pop();
        }
        return min_heap.top();
    }
};