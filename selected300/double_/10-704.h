#include "..\..\head.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid -1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = 0, low = 0, high = nums.size() - 1;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (nums[low] == target)
            return low;
        else 
            return -1;
    }
};