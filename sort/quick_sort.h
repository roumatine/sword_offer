#include "..\head.h"

/* 哨兵划分 */

int partition(vector<int> &nums, int left, int right) {
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left])
            j--;
        while (i < j && nums[i] <= nums[left])
            i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);
    return i;
}

/* 快速排序 */

void quick_sort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(nums, left, right);
    quick_sort(nums, left, pivot - 1);
    quick_sort(nums, pivot + 1, right);
}


/* 哨兵划分（三数取中值） */
int media_three(vector<int> &nums, int left, int mid, int right) {
    int l = nums[left];
    int m = nums[mid];
    int r = nums[right];
    if ((l <= m && m <= r) || (r <= m && m <= l)) {
        return mid; // m 在 l 和 r 之间
    }
    if ((m <= l && l <= r) || (r <= l && l <= m)) {
        return left; // l 在 m 和 r 之间
    }
    return right;
}

/* 哨兵划分（三数取中值） */
int paratition_both3(vector<int> &nums, int left, int right) {
    int med = media_three(nums, left, (left + right) / 2, right);
    swap(nums[left], nums[med]);
    // 以 nums[left] 为基准数
    int i = left, j = right;
    while(i < j) {
        while (i < j && nums[j] >= nums[left])
            j--;
        while (i < j && nums[i] <= nums[left])
            i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);
    return i;
}

/* 快速排序（尾递归优化） */
void quickSort(vector<int> &nums, int left, int right) {
    // 子数组长度为 1 时终止
    while (left < right) {
        // 哨兵划分操作
        int pivot = partition(nums, left, right);
        // 对两个子数组中较短的那个执行快速排序
        if (pivot - left < right - pivot) {
            quickSort(nums, left, pivot - 1); // 递归排序左子数组
            left = pivot + 1;                 // 剩余未排序区间为 [pivot + 1, right]
        } else {
            quickSort(nums, pivot + 1, right); // 递归排序右子数组
            right = pivot - 1;                 // 剩余未排序区间为 [left, pivot - 1]
        }
    }
}