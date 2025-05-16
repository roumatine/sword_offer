#include "..\..\head.h"

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, cnt = 0, res = 0;
        int size = nums.size();

        while (right < size) {
            if (nums[right] == 0) {
                cnt += 1;
            }
            while (cnt > k) {
                if (nums[left] == 0)
                    cnt -= 1;
                left ++;
            }
            res = max(res, right - left + 1);
            right ++;
        }
        return res;
    }
};