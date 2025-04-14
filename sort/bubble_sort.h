#include "..\head.h"
/* 冒泡排序 */
void bubble_sort(vector<int>& num) {
    int n = num.size();
    for (int i = num.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (num[j] > num[j + 1]) {
                swap(num[j], num[j + 1]);
            }
        }
    }
}

void bubble_sort_with_flag(vector<int>& nums) {
    for (int i = nums.size() - 1; i > 0; i--) {
        bool flag = false;
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                flag = true; // 记录交换元素
            }
        }
        if (!flag) {
            break;
        }
    }
}