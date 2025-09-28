#include "..\..\head.h"

class Solution
{
public:
    int addDigits(int num)
    {
        // 100a + 10b + c = (99a + a) + (9b + b) + c
        // = (99a + 9b) + (a + b + c) 从原数到最后的树根减少量一定是9的倍数
        return (num - 1) % 9 + 1;
    }

    int addDigits(int num)
    {
        while (num >= 10)
        {
            int sum = 0;
            while (num > 0)
            {
                sum += num % 10;
                num / 10;
            }
            num = sum;
        }
        return num;
    }
};