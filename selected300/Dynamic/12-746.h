#include "..\..\head.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> minCost(size);
        minCost[0] = 0;
        minCost[1] = min(cost[0], cost[1]);
        for (int i = 2; i < size; i++) {
            minCost[i] = min(minCost[i - 1] + cost[i], minCost[i - 2] + cost[i - 1]);
        }
        return minCost[size - 1];
    }
};



class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
    }
};