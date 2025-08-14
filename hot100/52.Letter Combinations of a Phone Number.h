#include "..\head.h"

class Solution
{
    const string MAPPING[10] = {"", "", "abc", "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits)
    {
        int n = digits.size();
        if (n == 0)
        {
            return {};
        }
        vector<string> ans;
        string path(n, 0);

        auto dfs = [&](this auto &&dfs, int i)
        {
            if (i == n)
            {
                ans.push_back(path);
                return;
            }

            for (char a : MAPPING[digits[i] - '0'])
            {
                path[i] = a;
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};