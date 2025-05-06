
#include "..\..\head.h"

int dominatIndex(vector<int> &nums) {
    int index = 0;
    int maxNum = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        if (maxNum < nums[i]) {
            maxNum = nums[i];
            index = i;
        }
    }
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (nums[i] * 2 > maxNum)
            return -1;
    }
    return index;
}