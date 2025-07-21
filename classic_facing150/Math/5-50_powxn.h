#include "..\..\head.h"

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        long long num = n;
        if (num < 0)
        {
            num = -num;
            x = 1 / x;
        }
        while (n)
        {
            if (n & 1)
            {
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }

    double myPow1(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }
        if (n == -1)
        {
            return 1 / x;
        }
        double half = myPow(x, n / 2);
        double rest = myPow(x, n % 2);
        return rest * half * half;
    }
};
