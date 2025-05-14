#include "..\..\head.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<int> vec1(n, 0), vec2(n, 0), vec3(n, 0);
        vec1[0] = -prices[0];
        vec2[0] = 0;
        for (int i = 1; i < n; ++i) {
            vec2[i] = vec1[i - 1] + prices[i];
            vec1[i] = max(vec1[i - 1], vec3[i - 1] - prices[i]);
            vec3[i] = max(vec3[i - 1], vec2[i - 1]);
        }
        return max(vec2[n - 1], vec3[n - 1]);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        for (int i = 1; i < n; ++i) {
            int newf0 = max(f0, f2 - prices[i]);
            int newf1 = f0 + prices[i];
            int newf2 = max(f1, f2);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }

        return max(f1, f2);
    }
};