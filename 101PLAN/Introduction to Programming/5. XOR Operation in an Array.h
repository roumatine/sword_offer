#include "..\..\head.h"

class Solution
{ // Xor 异或运算的规则为：不同则为1，相同则为0
  // 0 ^ n = n
  // n ^ n = 0
  // b ^ a ^ b ^ c = a ^ b ^ b ^ c = a ^ c 这里面b和b异或为0，可以理解为相互抵消了

    // Xnor 同或运算的规则为：不同则为0，相同则为1
    // 1010 xnor 1110 = 1011
public:
    // 时间空间复杂度O(1)解法
    int xorOperation(int n, int start)
    {
        int a = start / 2;
        int b = n & start & 1; // start & 1 判断起始数字是否为奇数,  n & 判断当起始数字为奇数时，是否有奇数个数字参与运算
        return (xor_n(a + n - 1) ^ xor_n(a - 1)) * 2 + b;
    }

    int xor_n(int n)
    {
        switch (n % 4)
        {
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n + 1;
        default:
            return 0;
        }
    }

    int xorOperation(int n, int start)
    {
        int m = start;
        int num[n];
        for (int i = 1; i < n; i++)
        {
            num[i] = start + 2 * i;
            m = m ^ num[i];
        }
        return m;
    }
};