#include "..\..\head.h"

class Solution
{
public:
    int mySqrt(int x)
    {
        long mid = 0;
        long left = 0;
        long right = x;
        while (left < right)
        {
            mid = (left + right + 1) / 2;
            long sq = mid * mid;
            if (sq > x)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        return (int)left;
    }
};

class Solution
{
    const int SQRT_INT_MAX = sqrt(INT_MAX);

public:
    int mySqrt(int x)
    {
        int left = 0;
        int right = min(x, SQRT_INT_MAX) + 1;
        while (left + 1 < right)
        {
            int m = (left + right) >> 1;
            (m * m <= x ? left : right) = m;
        }
        return left;
    }

    int mySqrt1(int x)
    {
        int l = 0, r = x;
        while (l < r)
        {

            int mid = (l + r) >> 1;
            if ((long long)mid * mid >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if ((long long)l * l == x)
            return l;
        return l - 1;
    }
};