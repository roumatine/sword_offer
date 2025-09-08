#include "..\head.h"

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnt;
        int max_cnt = 0;
        for (int x : nums)
        {
            cnt[x]++;
            max_cnt = max(max_cnt, cnt[x]);
        }

        vector<vector<int>> buckets(max_cnt + 1);
        for (auto &[x, c] : cnt)
        {
            buckets[c].push_back(x);
        }

        vector<int> ans;
        for (int i = max_cnt; i >= 0 && ans.size() < k; i--)
        {
            ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        }
        return ans;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> unmp;
        for (auto &x : nums)
        {
            unmp[x]++;
        }

        struct MyComparison
        {
            bool operator()(pair<int, int> &p1, pair<int, int> &p2)
            {
                return p1.second > p2.second;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparison> que;
        for (auto &a : unmp)
        {
            que.push(a);
            if (que.size() > k)
            {
                que.pop();
            }
        }
        vector<int> res;
        while (!que.empty())
        {
            res.emplace_back(que.top().first);
            que.pop();
        }
        return res;
    }
};