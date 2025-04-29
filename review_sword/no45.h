#include "..\head.h"

bool IsContinuous(vector<int> nums) {
    if (nums.size() <= 4) {
        return false;
    }
    sort(nums.begin(), nums.end());
    int countZero = 0;
    int index = 0;
    while (index < nums.size() && nums[index] == 0) {
        countZero++;
        index++;
    }
    for (int i = index; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return false;
        } else if (nums[i] + 1 == nums[i + 1]) {
            continue;
        } else {
            countZero -= (nums[i + 1] - nums[i] - 1);
        }
        if (countZero < 0)
            return false;
    }
    return countZero >= 0;
}

bool is_continuouse(vector<int> nums) {
    int len = nums.size();
    if (len < 5)
        return false;
    sort(nums.begin(), nums.end());
    int numZero = 0;
    int numInner = 0;
    for (int i = 0; i < len - 1; i++) {
        if (nums[i] == 0) {
            ++numZero;
        } else if (nums[i] == nums[i + 1]) {
            return false;
        } else {
            numInner += nums[i + 1] - nums[i] - 1;
        }
    }
    if (numZero >= numInner)
        return true;
    return false;
}