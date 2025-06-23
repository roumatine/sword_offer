#include "..\head.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // 初始化动态规划数组，dp[i][0]表示第i天不持有股票的最大利润，dp[i][1]表示第i天持有股票的最大利润
        vector<vector<int>> dp(n, vector<int>(2));
        
        // 初始化第一天不持有股票的利润为0
        dp[0][0] = 0;
        // 初始化第一天持有股票的利润为负第一天的股票价格，即买入股票的成本
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            // 第i天不持有股票的最大利润为,前一天不持有股票的利润和前一天持有股票加当天卖出的利润中的较大值
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 第i天持有股票的最大利润为前一天持有股票的利润和当天买入股票的利润中的较大值
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
            // 第一次买入时利润为 -prices[i]
        }
        return dp[n - 1][0]; // 返回最后一天不持有股票的最大利润，即整个交易期间能获得的最大利润
    }
};

class solution {
public:
    int maxprofit(vector<int> &prices) {
        // 初始化现金（利润）为0，表示尚未进行任何交易
        int cash = 0;
        // 初始化持有股票的状态，以第一天的股票价格的负值表示
        int hold = -prices[0];


        // 遍历股票价格列表，从第二天开始
        for (int i = 1; i < prices.size(); i++) {
            // 更新现金（利润），取更新前的现金和卖出股票后的现金的最大值
            cash = max(cash, hold + prices[i]);
            // 更新持有股票的状态，取更新前的状态和买入当天股票后的状态的最大值
            hold = max(hold, -prices[i]);
        }
        return cash;
    }
};