#include "..\head.h"

/* 获取元素 num 的第 k 位，其中 exp = 10^(k-1) */
int digit(int num, int exp) {
    // 传入 exp 而非 k 可以避免在此重复执行昂贵的次方计算
    return (num / exp) % 10;
}

void counting_sort_digit(vector<int> &nums, int exp) {
    vector<int>counter(10, 0);
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int d = digit(nums[i], exp);
        counter[d]++;
    }
    for (int i = 1; i < 10; i++) {
        counter[i] += counter[i - 1];
    }
    vector<int> res(n,0);
    for (int i = n - 1; i >= 0; i--) {
        int d = digit(nums[i], exp);
        int j = counter[d] - 1;
        res[j] = nums[i];
        counter[d]--;
    }
}

void radix_sort(vector<int> &nums) {
    int m = *max_element(nums.begin(), nums.end());
    for (int exp = 1; m >= exp; exp *= 10) {
        counting_sort_digit(nums,exp);
    }
}