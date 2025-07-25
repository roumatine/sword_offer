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

    int maxProfit(vector<int> &prices)
    {
        const int k = 2;
        vector<array<int, 2>> f(k + 2, {INT_MIN / 2, INT_MIN / 2});
        for (int j = 1; j <= k + 1; j++)
        {
            f[j][0] = 0;
        }
        for (int p : prices)
        {
            for (int j = k + 1; j > 0; j--)
            {
                f[j][0] = max(f[j][0], f[j][1] + p);
                f[j][1] = max(f[j][1], f[j - 2][0] - p);
            }
        }
        return f[k + 1][0];
    }
};