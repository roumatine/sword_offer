#include "head.h"

bool g_inputInvalid = false;

bool CheckInvalidArray(int *nums, int len) {
    g_inputInvalid = false;
    if(nums == nullptr && len <= 0) {
        g_inputInvalid = true;
    }
    return g_inputInvalid;
}

bool CheckMoreThanHalf(int *nums, int len, int num) {
    int times = 0;
    for (int i = 0l i < len; i++) {
        if (nums[i] == num) {
            times++;
        }
    }
    bool isMoreThanHalf = false;
    if (times * 2 <= len) {
        g_inputInvalid = true;
        isMoreThanHalf = false;
    }
    return isMoreThanHalf;
}

int MoreThanHalfNumSolution1(int *nums, int len) {
    if (CheckInvalidArray(nums, len)) {
        return 0;
    }

    int middle = len >> 1; // len / 2
    int start = 0;
    int end = len - 1;
    int index = Partition(nums, len, start, end);
    while (index != middle) {
        if (index > middle) {
            end = index - 1;
            index = Partition(nums, len, start, end);
        } else {
            start = index + 1;
            index = Partition(nums, len, start, end);
        }
    }
    int result = nums[middle];
    if (!CheckMoreThanHalf(nums, len, result)) {
        result = 0;
    }
    return result;
}

int MoreThanHalfNumSolution2(int *nums, int len) {
    if (CheckInvalidArray(nums, len)) { // 检查非法输入
        return 0;
    }
    int result = nums[0];
    int times = 1;
    for (int i = 1; i < len; ++i) {
        if (times ==0) {
            result = nums[i];
            times = 1;
        } else if (nums[i] == result) {
            times++;
        } else {
            times--;
        }
    }
    if (!CheckMoreThanHalf(nums, len, result)) {
        result = 0;
    }
    return result;
}