#include "..\head.h"

int min_cost_climbing_stairs_dp(vector<int> &cost) {
    int n = cost.size() - 1;
    if (n == 1 || n == 2) {
        return cost[n];
    }
    vector<int> dp(n + 1);
    dp[1] = cost[1];
    dp[2] = cost[2];
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return dp[n];
}

/* 爬楼梯最小代价：空间优化后的动态规划 */
int minCostClimbingStairsDPComp(vector<int> &cost) {
    int n = cost.size() - 1;
    if (n == 1 || n == 2)
        return cost[n];
    int a = cost[1], b = cost[2];
    for (int i = 3; i <= n; i++) {
        int tmp = b;
        b = min(a, tmp) + cost[i];
        a = tmp;
    }
    return b;
}