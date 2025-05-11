#include "..\..\head.h"

// 利用vector自定义排序
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> unmp;
        int len = s.length();
        for (auto &ch : s) {
            unmp[ch]++;
        }
        vector<pair<char, int>> vec;
        for (auto &i : unmp) {
            vec.emplace_back(i);
        }
        sort(vec.begin(), vec.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
            return a.second > b.second;
        });
        string ret;
        for (auto &[ch, num] : vec) {
            for (int i = 0; i < num; ++i) {
                ret.push_back(ch);
            }
        }
        return ret;
    }
};

// 优先队列
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> unmp;
        for (const auto &c : s) {
            ++unmp[c];
        }
        priority_queue<pair<int,char>> pq;
        for (const auto &m : unmp) {
            pq.push({m.second, m.first});
        }
        string ret;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            ret.append(t.first, t.second);
        }
        return ret;
    }
};

// 数组下标索引
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> unmp;
        for (const auto &c : s) {
            unmp[c]++;
        }
        
        vector<string> vec(s.size() + 1);
        string res;
        for (const auto &m : unmp) {
            vec[m.second].append(m.second, m.first);
        }
        for (int i = s.size(); i > 0; --i) {
            if (!vec[i].empty()) {
                res.append(vec[i]);
            }
        }
        return res;
    }
};