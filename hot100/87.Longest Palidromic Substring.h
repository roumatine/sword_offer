#include "..\head.h"

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int left = 0, right = 0;
        for (int i = 0; i < 2 * n - 1; i++)
        {
            int l = i / 2;
            int r = (i + 1) / 2;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            if (r - l - 1 > right - left)
            {
                left = l + 1;
                r = r;
            }
        }
        return s.substr(left, right - left);
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        vector dp(n, vector(n, 0));
        int imax = 0;
        int maxlen = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = (s[i] == s[j]) && (i + 1 > j - 1 || dp[i + 1][j - 1]);
                if (dp[i][j] && j - i + 1 > maxlen)
                {
                    imax = i;
                    maxlen = j - i + 1;
                }
            }
        }
        return s.substr(imax, maxlen);
    }
};