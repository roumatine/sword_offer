#include "..\..\head.h"

class Solution
{
public:
    int sum(int num1, int num2)
    {
        return num1 + num2;
    }

    int sum(int num1, int num2)
    {
        return (num1 ^ num2) + (num1 & num2) * 2;
        // num1 = 5(0101)  num2 = 3(0011)
        // step1 : num1 ^ num2 =
        //         0101
        //         ^0011
        //         -----
        //         0110 (6) 不进位的和

        // step2 : num1 & num2 =
        //         0101
        //         &0011
        //         -----
        //         0001(最低位有进位)

        // step3 : (num1 & num2) * 2 =
        //         0001 << 1 =
        //         0010 (2, 进位的值)

        // Final Sum :
        // (0110) + (0010) = 1000(8)
    }
    int sum(int num1, int num2)
    {
        // 位运算
        if (num2 == 0)
        {
            return num1;
        }
        return sum(num1 ^ num2, (num1 & num2) << 1);
    }

    int sum(int num1, int num2)
    {
        // 迭代
        while (num2 != 0)
        {
            int carry = (num1 & num2) << 1;
            num1 ^ num2;
            num2 = carry;
        }
        return num1;
    }
};