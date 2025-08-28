#include "..\head.h"

class Solution
{
public:
    string decodeString(string s)
    {
        if (s.empty())
        {
            return s;
        }

        if (isalpha(s[0]))
        {
            return s[0] + decodeString(s.substr(1));
        }

        int i = s.find('[');
        int balance = 1;
        for (int j = i + 1;; j++)
        {
            if (s[j] == '[')
            {
                balance++;
            }
            else if (s[j] == ']')
            {
                balance--;
                if (balance == 0)
                {
                    int k = stoi(s.substr(0, i));
                    string t = decodeString(s.substr(i + 1, j - i - 1));
                    string res;
                    while (k--)
                    {
                        res += t;
                    }
                    return res + decodeString(s.substr(j + 1));
                }
            }
        }
    }

    string decodeString_dfs(string s)
    {
        int i = 0;
        auto decode = [&](this auto &&decode) -> string
        {
            string res;
            int k = 0;
            while (i < s.size())
            {
                char c = s[i];
                i++;
                if (isalpha(c))
                {
                    res += c;
                }
                else if (isdigit(c))
                {
                    k = k * 10 + (c - '0');
                }
                else if (c == '[')
                {
                    string t = decode();
                    for (; k > 0; k--)
                    {
                        res += t;
                    }
                }
                else
                {
                    break;
                }
            }
            return res;
        };
        return decode();
    }

    string decodeString_stk(string s)
    {
        stack<pair<string, int>> stk;
        string res;
        int k = 0;
        for (char c : s)
        {
            if (isalpha(c))
            {
                res += c;
            }
            else if (isdigit(c))
            {
                k = k * 10 + (c - '0');
            }
            else if (c == '[')
            {
                stk.emplace(move(res), k);
                k = 0;
            }
            else
            {
                auto [pre_res, pre_k] = stk.top();
                stk.pop();
                while (pre_k--)
                {
                    pre_res += res;
                }
                res = move(pre_res);
            }
        }
        return res;
    }
};