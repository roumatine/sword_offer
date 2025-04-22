#include "..\head.h"
#include "no1.h"

bool hasFind(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low + 1 < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            high = mid;
        } else if (nums[mid] < target) {
            low = mid;
        } else {
            return true;
        }
    }
    if (nums[low] == target || nums[high] == target) {
        return true;
    }

    return false;
}

bool Find(int target, vector<vector<int>> array) {
    if (array.size() == 0 || array[0].size() == 0) {
        return false;
    }

    int row = array.size();
    for (int i = 0; i < row; i++) {
        if (hasFind(array[i], target)) {
            return true;
        }
    return false;
    }
}