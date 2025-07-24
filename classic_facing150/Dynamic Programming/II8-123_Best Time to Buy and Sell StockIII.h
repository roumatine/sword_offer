#include "..\..\head.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int sold_2 = 0;
        int sold_1 = 0;
        int hold_2 = -prices[0];
        int hold_1 = -prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            sold_2 = max(sold_2, hold_2 + prices[i]);
            hold_2 = max(hold_2, sold_1 - prices[i]);

            sold_1 = max(sold_1, hold_1 + prices[i]);
            hold_1 = max(hold_1, -prices[i]);
        }
        return sold_2;
    }
};