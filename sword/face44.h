#include "..\head.h"

bool is_continuous(int *nums, int len) {
    if (nums == nullptr || len < 1) {
        return false;
    }
    qsort(nums, len, sizeof(int), compare);
    int num_of_zero = 0;
    int num_of_gap = 0;

    for (int i = 0; i < len && nums[i] == 0; ++i) {
        ++num_of_zero;
    }
    int small = num_of_zero;
    int big = small + 1;
    while (big < len) {
        if (nums[small] == nums[big]) {
            return false;
        }
        num_of_gap += nums[big] - nums[small] - 1;
        small = big;
        ++big;
    }
    return (num_of_gap > num_of_zero) ? false : true;
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int*)b;
}