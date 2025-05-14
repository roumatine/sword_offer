#include "..\..\head.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int tmp = prices[0];
        int sum = 0;
        for (auto &a : prices) {
            if (a > tmp) {
                sum += a - tmp;
                tmp = a;
            } else {
                tmp = a;
            }
        }
        return sum;
    }
};
