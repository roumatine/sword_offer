#include "..\head.h"

vector<int> two_sum_brute_force(vector<int> &nums, int target) {
    int size = nums.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

vector<int> twoSumHashTable(vector<int> &nums, int target) {
    int size = nums.size();
    // 辅助哈希表，空间复杂度为 O(n)
    unordered_map<int, int> dic;
    // 单层循环，时间复杂度为 O(n)
    for (int i = 0; i < size; i++) {
        if (dic.find(target - nums[i]) != dic.end()) {
            return {dic[target - nums[i]], i};
        }
        dic.emplace(nums[i], i);
    }
    return {};
}