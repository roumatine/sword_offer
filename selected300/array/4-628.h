#include "..\..\head.h"

int maxiMunmProduct(vector<int> &nums) {
    if (nums.size() == 3) {
        return nums[0] * nums[1] * nums[2];
    }
    sort(nums.begin(), nums.end());
    int res = 0;
    int max = nums[nums.size() - 1];
    int lastMax = nums[nums.size() - 2];
    int secondMin = nums[1];

    if (secondMin < 0) {
        int tmp = nums[0] * secondMin * max;
        res = max * lastMax * nums[nums.size() - 3];
        res = res > tmp ? res : tmp;
    } else {
        res = max * lastMax * nums[nums.size() - 3];
    }
    return res;
    
}