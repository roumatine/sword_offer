#include "..\..\head.h"

int pivotIndex(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int tmp = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (tmp * 2 == sum - nums[i]) {
            return i;
        }
        tmp += nums[i];
    }
    return -1;
}