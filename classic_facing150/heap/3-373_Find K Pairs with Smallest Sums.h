#include "..\..\head.h"

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans;
        priority_queue<tuple<int, int, int>> pq;
        for (int i = 0; i < min(n, k); ++i)
        {
            pq.emplace(-nums1[i] - nums2[0], i, 0);
        } // pq.emplace(-nums1[0], nums2[0], 0, 0);
        while (ans.size() < k)
        {
            auto [_, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < m)
            {
                pq.emplace(-nums1[i] - nums2[j + 1], i, j + 1);
            }
        }
        return ans;
    }
};