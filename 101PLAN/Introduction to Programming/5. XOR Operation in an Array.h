#include "..\..\head.h"

class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int a = start / 2;
        int b = n & start & 1;
        return (xor_n(a + n - 1) ^ xor_n(a - 1) * 2 + b);
    }

    int xor_n(int n)
    {
        switch (n % 4)
        {
        case 0:
            return n;
        case 1:
            return 1;
        case2:
            return n + 1;
        default:
            return 0;
        }
    }
};