#include "..\head.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farest = 0;

        for (int i = 0; i < n - 1; i++) {
            // 更新最远可以到达的位置
            farest = max(farest, i + nums[i]);
            // 如果当前位置无法到达，返回false
            if (farest <= i) {
                return false;
            }
        }
        
        // 如果最远可以到达的位置大于等于数组的最后一个位置，返回true
        return farest >= n - 1;
    }
};