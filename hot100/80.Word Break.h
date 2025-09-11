#include "..\head.h"
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int max_len = ranges::max(wordDict, {}, &string::length).length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<int> memo(n + 1, -1);
        auto dfs = [&](this auto &&dfs, int i) -> bool
        {
            if (i == 0)
            {
                return true;
            }
            int &res = memo[i];
            if (res != -1)
            {
                return res;
            }
            for (int j = i - 1; j >= max(i - max_len, 0); j--)
            {
                if (words.count(s.substr(j, i - j)) && dfs(j))
                {
                    return res = true;
                }
            }
            return res = false;
        };
        return dfs(n);
    }
};