#include "..\..\head.h"

class NumArray {
    std::vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
    vector<int> sums;
};
