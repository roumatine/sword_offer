#include "..\..\head.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty())
            return 0;
        int size = prices.size();
        vector<int> hold(size), sold(hold);
        hold[0] = -prices[0];
        for (int i = 1; i < size; ++i) {
            sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
        }
        return sold[size - 1];
    }
};

// space review
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty())
            return 0;
        int size = prices.size();
        int sold = 0;
        int hold = -prices[0];
        for (int i = 1; i < size; ++i) {
            sold = max(sold, hold + prices[i] - fee);
            hold = max(hold, sold - prices[i]);
        }
        return sold;
    }
};

// greed
// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();
//         int buy = prices[0] + fee;
//         int profit = 0;
//         for (int i = 1; i < n; ++i) {
//             if (prices[i] + fee < buy) {
//                 buy = prices[i] + fee;
//             }
//             else if (prices[i] > buy) {
//                 profit += prices[i] - buy;
//                 buy = prices[i];
//             }
//         }
//         return profit;
//     }
// };
