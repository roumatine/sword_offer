#include "..\..\head.h"

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto &word : words) {
            ++cnt[word];
        }
        vector<string> res;
        for (auto &[key, value] : cnt) {
            res.push_back(key);
        }
        sort(res.begin(), res.end(), [&](string &a, string &b) { 
            return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b];
        });
        res.erase(res.begin() + k, res.end());
        return res;
    }
};