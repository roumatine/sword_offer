
#include "..\..\head.h"

double findMaxAverage(vector<int> &nums, int k) {
    vector<int> res;
    int i = 0;
    for (int i = 0; i < k; ++i) {
        res.push_back(nums[i]);
    }

    int sum = 0;
    for (auto &a : res) {
        sum += a;
    }
    int res = sum;
    for (; i < nums.size(); ++i) {
        sum -= res[i % k];
        res [i % k] = nums[i];
        sum += nums[i];
        res = max(sum, res);
    }
    return res*1.0 / k;
} 