#include "..\..\head.h"

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int cnt_s[128]{};
        int cnt_t[128]{};
        for (char c : t)
        {
            cnt_t[c]++;
        }

        int m = s.size();
        int res_left = -1;
        int res_right = m;
        int left = 0;
        for (int right = 0; right < m; ++right)
        {
            cnt_s[s[right]]++;
            while (Covered(cnt_s, cnt_t))
            {
                if (right - left < res_right - res_left)
                {
                    res_left = left;
                    res_right = right;
                }
                cnt_s[s[left]]--;
                left++;
            }
        }
        return res_left < 0 ? "" : s.substr(res_left, res_right - res_left + 1);
    }

private:
    bool Covered(int cnt_s[], int cnt_t[])
    {
        for (int i = 'A'; i <= 'Z'; ++i)
        {
            if (cnt_s[i] < cnt_t[i])
            {
                return false;
            }
        }
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (cnt_s[i] < cnt_t[i])
            {
                return false;
            }
        }
        return true;
    }
};