#include "..\..\head.h"

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> stk;
        istringstream ss(path);
        string s;
        while (getline(ss, s, '/'))
        {
            if (s.empty() || s == ".")
            {
                continue;
            }
            if (s != "..")
            {
                stk.push_back(s);
            }
            else if (!stk.empty())
            {
                stk.pop_back();
            }
        }
        string res;
        for (string &s : stk)
        {
            res += '/';
            res += s;
        }
        return stk.empty() ? "/" : res;
    }
};