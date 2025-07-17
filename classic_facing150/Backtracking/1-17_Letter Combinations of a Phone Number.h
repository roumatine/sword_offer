#include "..\..\head.h"

class Solution
{
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
                ans.emplace_back(path);
                return;
            }
            for (char c : MAPPING[digits[i] - '0'])
            {
                path[i] = c;
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }

private:
    const string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        int n = digits.size();
        if (n == 0)
        {
            return {};
        }
        vector<string> res;
        string path(n, 0);
        return res;
    }

private:
    string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(int i, int n, string digits, string &path, vector<string> &ans)
    {
        if (i == n)
        {
            ans.emplace(path);
            return;
        }
        for (char c : MAPPING[digits[i] - '0'])
        {
            path[i] = c;
            dfs(i + 1, n, digits, path, ans);
        }
    }
};