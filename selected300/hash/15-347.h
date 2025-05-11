#include "..\..\head.h"

class Solution {
public:
    bool static cmp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> unmp(nums.size());
        for (auto &a : nums) {
            unmp[a] ++;
        }
        vector<pair<int, int>> tmp(unmp.begin(), unmp.end());
        sort(tmp.begin(), tmp.end(), cmp);

        vector<int> res;
        res.reserve(k);
        auto beg = tmp.begin();
        while (k --) {
            res.push_back(beg->first);
            beg++;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 第一步：统计每个元素的出现次数
        unordered_map<int, int> cnt;
        int max_cnt = 0;
        for (int x : nums) {
            cnt[x] ++;
            max_cnt = max(max_cnt, cnt[x]);
        }
        // 第二步：把出现次数相同的元素，放到同一个桶中
        vector<vector<int>> buckets(max_cnt + 1);
        for (auto & [x, c] : cnt) {
            buckets[c].push_back(x);
        }
        // 第三步：倒序遍历 buckets，把出现次数前 k 大的元素加入答案
        vector<int> ans;
        for (int i = max_cnt; i >= 0 && ans.size() < k; --i) {
            ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        }
        return ans;
    }
};