#include "..\..\head.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        else if (n == 1) 
            return nums[0];
        else if (n == 2)
            return max(nums[0], nums[1]);
        
        vector<int> res(n + 1, 0);
        res[1] = nums[0];
        res[2] = nums[1];
        for (int i = 2; i < n; ++i) {
            res[i + 1] = max(res[i - 1], res[i - 2]) + nums[i];
        }
        return max(res[n], res[n - 1]);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int size = nums.size();
        if (size == 1)
            return nums[0];
        vector<int> vec = vector<int>(size, 0);
        vec[0] = nums[0];
        vec[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
            vec[i] = max(vec[i - 2] + nums[i], vec[i - 1]);
        }
        return vec[size - 1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int size = nums.size();
        if (size == 1)
            return nums[0];
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};