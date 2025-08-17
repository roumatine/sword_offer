#include "..\head.h"

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.size();

        auto dfs = [&](this auto &&dfs, int i)
        {
            if (i == n)
            {
                ans.push_back(path);
                return;
            }

            for (int j = i; j < n; j++)
            {
                if (isPalindrome(s, i, j))
                {
                    path.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }

    bool isPalindrome(const string &s, int left, int right)
    {
        // 判断回文
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s)
    {
        // 选或者不选
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> path;

        auto dfs = [&](this auto &&dfs, int i, int j)
        {
            if (i == n)
            {
                ans.emplace_back(path);
                return;
            }

            if (i < n - 1)
            {
                dfs(i + 1, j);
            }
            if (isPalindrome(s, j, i))
            {
                path.emplace_back(s.substr(j, i - j + 1));
                dfs(i + 1, i + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};