/*
非递减数列
*/

#include "..\..\head.h"

bool checkPossibility(vector<int> &nums) {
    if (nums.size() <= 2) 
        return true;
    int cnt = 0;
    for (int i = 0; i < nums.size() && cnt < 2; ++i) {
        if (nums[i - 1] <= nums[i])
            continue;
        cnt ++;
        if (i >= 2 && nums[i - 2] > nums[i])
            nums[i] = nums[i - 1];
        else 
            nums[i - 1] = nums[i];
    }
    return cnt <= 1;
}