#include "..\..\head.h"

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> res(n + 1, 0);
        res[1] = 1;
        res[2] = 2;
        for (int i = 3; i <= n; ++i) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n];
    }
};

class Solution {
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; ++i) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};