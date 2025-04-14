#include "..\head.h"
/* 选择排序 */
void selection_sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i ++) {
        int k = i;
        for (int j = i + 1; j < n; j ++) {
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        swap(nums[i], nums[k]);
    }
}