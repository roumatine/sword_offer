#include "..\..\head.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int len = nums.size();
        if (len == 1)
            return nums[0];
        vector<int> vec1(len, 0);
        vector<int> vec2(len, 0);
        vec1[1] = nums[0];
        vec2[1] = nums[1];

        for (int i = 2; i < len; ++i) {
            vec1[i] = max(vec1[i - 1], nums[i - 1] + vec1[i - 2]);
        }
        for (int i = 2; i < len; ++i) {
            vec2[i] = max(vec2[i - 1], nums[i] + vec2[i - 2]);
        }
        return max(vec1[len - 1], vec2[len - 1]);
    }
};


class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start];
        int second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; ++i) {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        } else if (len == 2) {
            return max(nums[0], nums[1]); 
        }
        return max(robRange(nums, 0, len - 2), robRange(nums, 1, len - 1));
    }
};