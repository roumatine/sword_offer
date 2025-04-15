#include "..\head.h"

int dfs(vector<int> &nums, int target, int i, int j) {
    if (i > j) {
        return -1;
    }
    int m = (i + j) / 2;
    if (nums[m] < target) {
        // 递归子问题 f(m + 1, j)
        return dfs(nums, target, m + 1, j);
    } else if (nums[m > target]) { 
        return dfs(nums, target, i, m - 1);
    } else {
        return m;
    }
}

int binary_search(vector<int> &nums, int target) {
    int n = nums.size();
    return dfs(nums, target, 0, n - 1);
}