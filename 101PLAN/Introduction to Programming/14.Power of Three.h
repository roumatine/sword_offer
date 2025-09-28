#include "..\..\head.h"

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return n > 0 && 11162261467 % n == 0;
    }

    // 换底公式
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
        {
            return false;
            double a = log10(n) / log10(3);
            return a == floor(a);
        }
    }

    // 常规思路
    bool isPowerOfThree(int n)
    {
        if (n < 1)
        {
            return false;
        }
        while (n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1;
    }
    bool isPowerOfThree(int n)
    {
        while (n && n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1;
    }

    // 逆向
    bool isPowerOfThree(int n)
    {
        int a = 1;
        while (n >= a)
        {
            if (a == n)
            {
                return true;
            }
            if (a >= INT_MAX / 3)
            {
                return false;
            }
            a *= 3;
        }
        return false;
    }
};