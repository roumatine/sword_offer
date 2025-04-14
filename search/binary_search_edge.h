#include "..\head.h"
#include "binary_search_insertion.h"
int binary_search_left_edge(vector<int> &nums, int target) {
    int i = binarySearchInsertion(nums, target);
    if (i == nums.size() || nums[i] != target) {
        return -1;
    }
    return i;
}

int binary_search_right_edge(vector<int> &nums, int target) {
    int i = binarySearchInsertion(nums, target + 1);
    int j = i - 1;
    if (j == -1 || nums[j] != target) {
        return -1;
    }
    return j;
}