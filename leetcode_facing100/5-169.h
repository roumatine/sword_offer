#include "..\head.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 如果计数器为0，表示当前候选元素已被消除，选择新的候选元素
            if (cnt == 0) {
                target = nums[i]; // 0
                cnt = 1; // 1
            } else if (nums[i] == target) {
                // 如果当前元素与候选元素相同，计数器加1
                cnt ++;
            } else {
                // 如果当前元素与候选元素不同，计数器减1
                cnt --;
            }
        }
        return target;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = 0;
        int cnt = 0;
        for (int num : nums) {
            // 如果计数器为零，表示当前候选元素已被排除，选择新的候选元素
            if (cnt == 0)
                i = num;
            // 更新计数器，如果当前元素与候选元素相同，计数器增加；否则，计数器减少
            cnt += num == i ? 1 : -1;
        }
        return i;
    }
};