#include "..\..\head.h"

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> errorNum(2);
        int n = nums.size();
        unordered_map<int, int> unmp;
        for (auto &num : nums) {
            unmp[num] ++;
        }
        for (int i = 1; i <= n; ++i) {
            int cnt = unmp[i];
            if (cnt == 2) {
                errorNum[0] = i;
            } else if (cnt == 0) {
                errorNum[1] = i;
            }
        }
        return errorNum;
    }
};

// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         vector<int> vec;
//         for (int i = 0; i < nums.size(); ++ i) {
//             while (i + 1 != nums[i] && nums[i] != nums[nums[i] - 1]) {
//                 swap(nums[i], nums[nums[i] - 1]);
//             }
//         }
//         for (int i = 0; i < nums.size(); ++ i) {
//             if (i + 1 != nums[i]) {
//                 vec.emplace_back(nums[i]);
//                 vec.emplace_back(i + 1);
//                 break;
//             }
//         }
//         return vec;
//     }
// };

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> unset;
        int len = nums.size();
        int sum = 0;
        int res = 0;
        sum  = (len + 1) * len / 2;
        for (int i = 0; i < len; ++i) {
            if (unset.insert(nums[i]).second) {
                sum -= nums[i];
            } else {
                res = nums[i];
            }
        }
        return {res, sum};
    }
};