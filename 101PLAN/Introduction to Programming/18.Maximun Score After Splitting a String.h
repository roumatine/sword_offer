#include "..\..\head.h"

class Solution
{
public:
    int maxScore(string s)
    {
        int right = ranges::count(s, '1');
        int ans = 0, left = 0;
        for (int i = 0; i + 1 < s.size(); i++)
        {
            if (s[i] == '0')
            {
                left++;
            }
            else
            {
                right--;
            }
            ans = max(ans, left + right);
        }
        return ans;
    }

    int maxScore(string s)
    {
        int n = s.size();
        int presum = 0, ans = -1 - n;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && presum * 2 - i > ans)
            {
                ans = presum * 2 - i;
            }
            presum += s[i] == '0' ? 1 : 0;
        }
        return ans + n - presum;
    }

    int maxScore(string s)
    {
        int score = ranges::count(s, '1');
        int ans = 0;
        for (int i = 0; i + 1 < s.size(); i++)
        {
            score += s[i] == '0' ? 1 : -1;
            ans = max(ans, score);
        }
        return ans;
    }

    int maxScore(string s)
    {
        int cntl0 = 0, cntr1 = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (c == '1')
                cntr1++;
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            char c = s[i];
            if (c == '0')
                cntl0++;
            else
                cntr1--;
            ans = max(ans, cntl0 + cntr1);
        }
        return ans;
    }
};