#include "..\..\head.h"

class Solution
{
public:
    int smallestEvenMultiple(int n)
    {
        return (n % 2 == 0) ? n : n * 2;
        // return (n % 2 + 1) * n;
        // return n << (n & 1);
    }

    int smallestEvenMultiple(int n)
    {
        if (n & 1)
        {
            return 2 * n;
        }
        return n;
    }
};