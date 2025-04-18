
#include "..\head.h"

int coin_change(vector<int> &coins, int amount) {
    int n = coins.size();
    int max = amount + 1;
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int a = 1; a <= amount; a ++) {
        dp[0][a] = max;
    }
    for (int i = 1; i <= n; i ++) {
        for (int a = 1; a <= amount; a++) {
            if (coins[i - 1] > a) {
                dp[i][a] = dp[i - 1][a];
            } else {
                dp[i][a] = min(dp[i - 1][a], dp[i][a - coins[i - 1]] + 1);
            }
        }
    }
    return dp[n][amount] != max ? dp[n][amount] : -1;
}

/* 零钱兑换：空间优化后的动态规划 */
int coinChangeDPComp(vector<int> &coins, int amt) {
    int n = coins.size();
    int MAX = amt + 1;
    // 初始化 dp 表
    vector<int> dp(amt + 1, MAX);
    dp[0] = 0;
    // 状态转移
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // 若超过目标金额，则不选硬币 i
                dp[a] = dp[a];
            } else {
                // 不选和选硬币 i 这两种方案的较小值
                dp[a] = min(dp[a], dp[a - coins[i - 1]] + 1);
            }
        }
    }
    return dp[amt] != MAX ? dp[amt] : -1;
}