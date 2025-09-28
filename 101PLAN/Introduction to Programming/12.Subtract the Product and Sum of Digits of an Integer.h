#include "..\..\head.h"

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int prod = 1;
        int sum = 0;
        while (n)
        {
            prod *= n % 10;
            sum += n % 10;
            n /= 10;
        }
        return prod - sum;
    }

    int subtractProductAndSum(int n)
    {
        int m = 1;
        int s = 0;
        while (n)
        {
            int x = n % 10;
            n /= 10;
            m *= x;
            s += x;
        }
        return m - s;
    }

    // 字符串
    int subtractProductAndSum(int n)
    {
        int a = 1, b = 0;
        string s = to_string(n);
        for (int i = 0; i < s.size(); ++i)
        {
            a *= s[i] - '0';
            b += s[i] - '0';
        }
        return a - b;
    }
};