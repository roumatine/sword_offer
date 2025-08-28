#include "..\head.h"

class Solution
{
    unordered_map<char, char> mp = {{')', '('}, {']', '['}, {'}', '{'}};
    unordered_map<char, char> mp2 = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

public:
    bool isValid(string s)
    {
        if (s.length() % 2)
        {
            return false;
        }

        stack<char> stk;
        for (char c : s)
        {
            if (!mp.contains(c))
            { // mp.contains(c) 用来判断 c 是不是 mp 的一个 key
                stk.push(c);
            }
            else
            {
                if (stk.empty() || stk.top() != mp[c])
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }

    bool isValid_ifelse(string s)
    {
        if (s.length() % 2)
        {
            return false;
        }
        stack<char> stk;
        for (char c : s)
        {
            if (c == '(')
            {
                stk.push(')');
            }
            else if (c == '[')
            {
                stk.push(']');
            }
            else if (c == '{')
            {
                stk.push('}');
            }
            else
            {
                if (stk.empty() || stk.top() != c)
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }

    bool isValid_2(string s)
    {
        if (s.size() % 2)
        {
            return false;
        }

        stack<char> stk;
        for (char c : s)
        {
            if (mp2.contains(c))
            {
                stk.push(mp2[c]);
            }
            else
            {
                if (stk.empty() || stk.top() != c)
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};