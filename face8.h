#include "head.h"

int MinInOrder(int *nums, int index1, int index2) {
    int result = nums[index1];
    for (int i = index1 + 1; i <= index2; i++) {
        if ( result > nums[i] ) {
            result = nums[i];
        }
    }
    return result;
}

int Min(int* nums, int len) {
    if (nums == nullptr || len <= 0) {
        std::cout << "Invalid parameters" << std::endl;
        return -1;
    }

    int index1 = 0;
    int index2 = len -1;
    int indexMid = index1;
    while (nums[index1] >= nums[index2]) {
        if (index2 - index1 == 1) {
            indexMid = index2;
            break;
        }
    
        indexMid = (index1 + index2) /2;
        if (nums[index1] == nums[index2] && nums[indexMid] == nums[index1]) {
            return MinInOrder(nums, index1, index2);
        }
        if (nums[indexMid] >= nums[index1]) {
            index1 = indexMid;
        } else if (nums[indexMid] <= nums[index2]) {
            index2 = indexMid;
        }
    }
    return nums[indexMid];
}