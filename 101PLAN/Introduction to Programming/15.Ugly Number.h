#include "..\..\head.h"

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        while (n % 3 == 0)
        {
            n /= 3;
        }
        while (n % 5 == 0)
        {
            n /= 5;
        }
        return (n & (n - 1)) == 0;
        // 最后，n 必须只剩下因子 2,即 2的k次幂
    }

    bool isUgly(int n)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else if (n % 3 == 0)
        {
            n /= 3;
        }
        else if (n % 5 == 0)
        {
            n /= 5;
        }
        return n == 1;
    }
};