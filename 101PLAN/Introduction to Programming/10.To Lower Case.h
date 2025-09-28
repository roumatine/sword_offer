#include "..\..\head.h"

class Solution
{
public:
    string toLowerCase(string s)
    { // 特殊符号 @[] 难区分
        for (auto &i : s)
        {
            i |= 32;
        }
        return s;
    }

    string toLowerCase(string s)
    {
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (s[i] <= 'Z' && s[i] >= 'A')
            {
                s[i] = s[i] + 32;
            }
        }
        return s;
    }

    string toLowerCase(string s)
    {
        const int len = s.size();
        for (int i = 0; i < len; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 'a' - 'A';
        }
        return s;
    }
};