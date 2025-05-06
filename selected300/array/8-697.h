/*
数组的度
*/

#include "..\..\head.h"

int findShortSubArray(vector<int> &nums) {
    unordered_map<int, vector<int>> unmp;
    int span = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        unmp[nums[i]].push_back(i);
        span = span > unmp[nums[i]].size() ? span : unmp[nums[i]].size();
    }
    int minLen = nums.size();
    int tmp;
    for (auto & u : unmp) {
        if (u.second.size() == span) {
            tmp = u.second[u.second.size() - 1] - u.second[0];
            minLen = minLen < tmp ? minLen : tmp;
        }
    }
    return minLen + 1;
}