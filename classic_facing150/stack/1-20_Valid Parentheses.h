#include "..\..\head.h"
class Solution
{
    unordered_map<char, char> unmp = {{')', '('}, {']', '['}, {'}', '{'}};

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
            if (!unmp.contains(c))
            {
                stk.push(c);
            }
            else
            {
                if (stk.empty() || stk.top() != unmp[c])
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};

class Solution
{
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
};