#include "..\head.h"

int climbing_stairs_dp(int n) {
    if (n == 1 || n == 2) {
        return n;
    }
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int climbing_stairs_dp_comp(int n) {
    if (n == 1 || n == 2) {
        return n;
    }
    int a = 1, b = 2;
    int tmp = 0;
    for (int i = 3; i <= n; ++i) {
        tmp = a + b;
        a = b;
        b = tmp;
    }
    return b;
}