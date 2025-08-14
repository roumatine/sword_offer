#include "..\head.h"

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string path(n * 2, 0);

        auto dfs = [&](this auto &&dfs, int left, int right) -> void
        {
            if (right == n)
            {
                ans.push_back(path);
                return;
            }
            if (left < n)
            {
                path[left + right] = '(';
                dfs(left + 1, right);
            }
            if (right < left)
            {
                path[left + right] = ')';
                dfs(left, right + 1);
            }
        };
        dfs(0, 0);
        return ans;
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        vector<int> path;

        auto dfs = [&](this auto &&dfs, int i, int balace)
        {
            if (path.size() == n)
            {
                string s(n * 2, ')');
                for (int j : path)
                {
                    s[j] = '(';
                }
                ans.push_back(s);
                return;
            }
            for (int right = 0; right <= balace; right++)
            {
                path.push_back(i + right);
                dfs(i + right + 1, balace - right + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};