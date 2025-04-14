#include "..\head.h"

int binary_search_insertion_simple(vector<int> &nums, int target) {
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j)
    {
        /* code */
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        } else if (nums[m] > target) {
            j = m - 1;
        } else {
            return m;
        }
    }
    return i;
}

/* 二分查找插入点（存在重复元素） */
int binarySearchInsertion(vector<int> &nums, int target) { 
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j) {
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        } else if (nums[m] > target) {
            j = m - 1;
        } else {
            j = m - 1;
        }
    }
    return 1;
}