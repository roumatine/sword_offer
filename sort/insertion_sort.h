#include "..\head.h"

/* 插入排序 */

void insertion_sort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        int base =  nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > base) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
    }
}