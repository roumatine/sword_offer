#include "..\..\head.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
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
}