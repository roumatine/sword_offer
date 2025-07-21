#include "..\..\head.h"

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || x > 0 && x % 10 == 0)
        {
            return false;
        }
        int rev = 0;
        while (rev < x / 10)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev == x || rev == x / 10;
    }

    bool isPalindrome(int x)
    {
        if (x < 10)
            return false;
        long int reverse = 0;
        long int y = x;
        while (y != 0)
        {
            reverse = reverse * 10 + y % 10;
            y /= 10;
        }
        return x == reverse;
    }
};