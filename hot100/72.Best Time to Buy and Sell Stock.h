#include "..\head.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int min_price = prices[0];
        for (int x : prices)
        {
            ans = max(ans, x - min_price);
            min_price = min(min_price, x);
        }
        return ans;
    }

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

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1)
        {
            return 0;
        }
        int min_price = prices[0];
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            min_price = min(prices[i], min_price);
            ans = max(ans, prices[i] - min_price);
        }
    }
};