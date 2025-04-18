#include "..\head.h"
int coin_change_ii(vector<int> &coins, int amt) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                dp[i][a] = dp[i - 1][a];
            } else {
                dp[i][a] = dp[i - 1][a] + dp[i][a - coins[i - 1]];
            }
            
        }
    }
    return dp[n][amt];
}

/* 零钱兑换 II：空间优化后的动态规划 */
int coinChangeIIDPComp(vector<int> &coins, int amt) {
    int n = coins.size();
    // 初始化 dp 表
    vector<int> dp(amt + 1, 0);
    dp[0] = 1;
    // 状态转移
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // 若超过目标金额，则不选硬币 i
                dp[a] = dp[a];
            } else {
                // 不选和选硬币 i 这两种方案之和
                dp[a] = dp[a] + dp[a - coins[i - 1]];
            }
        }
    }
    return dp[amt];
}