#include "..\head.h"

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        deque<int> q;
        for (int i = 0; i < n; i++)
        {
            while (!q.empty() && nums[q.back() <= nums[i]])
            {
                q.pop_back();
            }
            q.push_back(i);

            int left = i - k + i;
            if (q.front() < left)
            {
                q.pop_front();
            }
            if (left >= 0) // i >= k - 1
            {
                ans[left] = nums[q.front()];
            }
        }
        return ans;
    }
};