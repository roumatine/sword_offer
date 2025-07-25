#include "..\..\head.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int cash = 0;
        int hold = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            cash = max(cash, hold + prices[i]);
            hold = max(hold, -prices[i]);
        }
        return cash;
    }

    int maxProfit_1(vector<int> &prices)
    {
        int ans = 0;
        int min_price = prices[0];
        for (int p : prices)
        {
            ans = max(ans, p - min_price);
            min_price = min(min_price, p);
        }
        return ans;
    }
};