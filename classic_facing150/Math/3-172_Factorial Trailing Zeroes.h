#include "..\..\head.h"

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        while (n)
        {
            n /= 5;
            ans += n;
        }
        return ans;
    }

    int trailingZeroes(int n)
    {
        int ans = 0;
        for (int i = 5; i <= n; i += 5)
        {
            for (int x = i; x % 5 == 0; x /= 5)
            {
                ++ans;
            }
        }
        return ans;
    }
};