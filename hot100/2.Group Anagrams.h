#include "..\head.h"

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> unmp;
        for (string &s : strs)
        {
            string sort_s = s;
            ranges::sort(sort_s); // sort(sort_s.begin(), sort_s.end());
            unmp[sort_s].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(unmp.size());
        for (auto &[_, value] : unmp)
        {
            ans.push_back(value);
        }
        return ans;
    }
};