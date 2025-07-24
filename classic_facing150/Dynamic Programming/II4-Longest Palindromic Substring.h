#include "..\..\head.h"

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int ans_left = 0;
        int ans_right = 0;
        // 奇
        for (int i = 0; i < n; i++)
        {
            int l = i;
            int r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            if (r - l - 1 > ans_right - ans_left)
            {
                ans_left = l + 1;
                ans_right = r;
            }
        }
        // 偶
        for (int i = 0; i < n - 1; i++)
        {
            int l = i;
            int r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            if (r - l - 1 > ans_right - ans_left)
            {
                ans_left = l + 1;
                ans_right = r;
            }
        }
        return s.substr(ans_left, ans_right - ans_left);
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        int ans_left = 0;
        int ans_right = 0;

        for (int i = 0; i < 2 * n - 1; i++)
        {
            int l = i / 2;
            int r = (i + 1) / 2;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            if (r - l - 1 > ans_right - ans_left)
            {
                ans_left = l + 1;
                ans_right = r;
            }
        }
        return s.substr(ans_left, ans_right - ans_left);
    }
};