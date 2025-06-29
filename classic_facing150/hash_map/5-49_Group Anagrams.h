#include "..\..\head.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> unmp;
        for (string & s : strs) {
            string sort_s = s;
            sort(sort_s.begin(), sort_s.end());
            unmp[sort_s].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(unmp.size());
        for (auto &[_, value] : unmp) {
            res.push_back(value);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> vec;
        for (const string &s : strs) {
            string code = encode(s);
            vec[code].push_back(s);
        }
        vector<vector<string>> res;
        for (auto & c : vec) {
            res.push_back(vector<string>(c.second.begin(), c.second.end()));
        }
    }
private:
    std::string encode(const string &s) {
        string cnt(26, '0');
        for (char c : s) {
            int dlt = c - 'a';
            cnt[dlt] ++;
        }
        return cnt;
    }
};