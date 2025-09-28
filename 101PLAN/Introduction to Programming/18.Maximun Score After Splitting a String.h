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
};