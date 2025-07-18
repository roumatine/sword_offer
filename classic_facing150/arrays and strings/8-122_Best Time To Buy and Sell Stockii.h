#include "..\head.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2));

        for (int i = 1; i < n; i++) {
            // 对于数组中的第一个元素，特殊处理
            if (i - 1 == -1) {
                // 第一天不持有股票的利润为0
                dp[i][0] = 0;
                // 第一天持有股票的利润为负的股票价格
                dp[i][1] = -prices[i];
            }
            // 更新第i天不持有股票的最大利润，考虑前一天不持有和前一天持有但今天卖出的情况
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 更新第i天持有股票的最大利润，考虑前一天持有和前一天不持有但今天买入的情况
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};