#include "..\..\head.h"

int FindUnsortedSubarray(vector<int> &nums) {
    int len = nums.size();
    int low = 0;
    int high = len - 1;
    int maxNums = nums[0];
    int minNums = nums[len - 1];

    for (int i = 1; i < len; i++) {
        maxNums = max(maxNums, nums[i]);
        minNums = min(minNums, nums[len - 1 - i]);
        if (nums[i] < maxNums) 
            low = i;
        if (nums[len - 1 - i] > minNums)
            high = len - 1 - i;
    }
    return low > high ? low - high + 1 : 0;
}

int find_unsorted_subarray(vector<int> &nums) {
    if (nums.size() == 1)
        return 0;
    int low = 0;
    int high = nums.size() - 1;
    int len = nums.size();
    int maxNums = nums[0];
    int minNums = nums[high];
    
    for (int i = 1; i < len; i++) {
        maxNums = max(nums[i], maxNums);
        if (nums[i] < maxNums)
            low = i;
        minNums = min(nums[len - 1 - i], minNums);
        if (nums[len - i - 1] > minNums)
            high = len - i - 1;
    }
    return low > high ? low - high + 1 : 0;
}