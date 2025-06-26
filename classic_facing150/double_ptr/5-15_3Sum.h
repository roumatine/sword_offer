#include "..\..\head.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return nSum(nums, 3, 0, 0);
    }
private:
    vector<vector<int>> nSum(vector<int> &nums, int n, int start, long long target) {
        int size = nums.size();
        vector<vector<int>> res;
        if (n < 2 || size < n)
            return res; // 至少是 2Sum
        if (n == 2) {
            int slow = start;
            int fast = size - 1;
            while (slow < fast) {
                int sum = nums[slow] + nums[fast];
                int left = nums[slow];
                int right = nums[fast];
                if (sum < target) {
                    while (slow < fast && nums[slow] == left) {
                        slow ++;
                    }
                } else if (sum > target) {
                    while (slow < fast && nums[fast] == right) {
                        fast --;
                    }
                } else {
                    res.push_back({left, right});
                    while (slow < fast && nums[slow] == left) {
                        slow ++;
                    }
                    while (slow < fast && nums[fast] == right) {
                        fast --;
                    }
                }
            }
        } else {
            for (int i = start; i < size; ++i) {
                vector<vector<int>> sub = nSum(nums, n - 1, i + 1, target - nums[i]);
                for (auto &vec : sub) {
                    vec.push_back(nums[i]);
                    res.push_back(vec);
                }
                while (i < size - 1 && nums[i] == nums[i + 1]) {
                    ++i;
                }
            }
        }
        return res;
    }
};