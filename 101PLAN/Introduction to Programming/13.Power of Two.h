#include "..\..\head.h"

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
        // return n > 0 && (1 << 31) % n == 0;
        // return n > 0 && (n ^ (n & -n)) == 0;
    }

    bool isPowerOfTwo(int n)
    {
        // 相当于乘法
        // 通过左位移操作，列举出 int 型内的全部2的幂次方
        if (!n)
        {
            return false;
        }
        for (int i = 1, sub = 1; i < 32; ++i, sub <<= 1)
        {
            if (sub == n)
            {
                return true;
            }
        }
        return false;
    }

    bool isPowerOfTwo(int n)
    { // 相当于除法
        if (!n)
        {
            return n;
        }
        while (n % 2 == 0)
        {
            n >>= 1;
        }
        return n == 1;
    }

    bool isPowerOfTwo(int n)
    {
        long long num = 1;
        for (int i = 0; i >= 0; ++i)
        {
            num *= 2;
            if (num >= n)
            {
                break;
            }
        }
        if (num == n)
        {
            return true;
        }
        else if (n == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};