#include "..\head.h"

static bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] - a[1] < b[0] - b[1];
}

int towCitySchedConst(vector<vector<int>> & costs) {
    sort(costs.begin(), costs.end(), cmp);
    int cnt = 0;
    int sum = 0;
    int len = costs.size();
    for (auto &cost : costs) {
        if (cnt * 2 < len)
            sum += cost[0];
        else 
            sum += cost[1];
        cnt++;
    }
    return sum;
} 


class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(begin(costs), end(costs), [](const vector<int>&a, const vector<int>&b) {
            return (a[0] - a[1] < b[0] - b[1]);
        });
        int total = 0;
        int n = costs.size() / 2;
        for (int i = 0; i < n; ++i) {
            total += cost[i][0] + costs[i+n][1];
        }
        return total;
    }
};
