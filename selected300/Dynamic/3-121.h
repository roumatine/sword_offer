#include "..\..\head.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int minNum = prices[0];
        int maxNum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            maxNum = max(maxNum, prices[i] - minNum);
            minNum = min(minNum, prices[i]);
        }
        return maxNum;
    }
};