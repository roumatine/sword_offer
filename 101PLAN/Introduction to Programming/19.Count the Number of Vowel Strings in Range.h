#include "..\..\head.h"

class Solution
{
public:
    int vowelStrings(vector<string> &words, int left, int right)
    {
        const string vowel = "aeiou";
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            string &s = words[i];
            ans += vowel.find(s[0]) != string::npos && vowel.find(s.back()) != string::npos;
        }
        return ans;
    }

    // 库函数
    int vowelStrings(vector<string> &words, int left, int right)
    {
        int ans = 0;
        for (int i = left; i <= right; ++i)
        {
            string s = words[i];
            if (s.find_first_of("aeiou") == 0 && s.find_last_not_of("aeiou") == s.size() - 1)
            {
                ans++;
            }
        }
        return ans;
    }

    int check(string u)
    {
        int c = u.size() - 1;
        return (u[0] == 'a' || u[0] == 'e' || u[0] == 'i' || u[0] == 'o' ||
                u[0] == 'u') &&
               (u[c] == 'a' || u[c] == 'e' || u[c] == 'i' || u[c] == 'o' ||
                u[c] == 'u');
    }
    int vowelStrings(vector<string> &words, int left, int right)
    {
        int t = 0;
        for (int i = left; i <= right; i++)
        {
            t += check(words[i]);
        }
        return t;
    }
};