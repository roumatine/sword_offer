#include "..\..\head.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int sum = 0;
        for (auto a : nums) {
            if (sum + a > a) {
                sum += a;
            } else {
                sum = a;
            }
            result = sum > result ? sum : result; // max(sum, result)
        }
        return result;
    }
};

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if (nums.empty())
//             return 0;
//         vector<int> res(nums.size());
//         res[0] = nums[0];
//         int result = res[0];
//         for (int i = 1; i < nums.size(); ++i) {
//             res[i] = max(0, res[i - 1]) + nums[i];
//             result = max(result, res[i]);
//         }
//         return result;
//     }
// };