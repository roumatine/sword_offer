#include "..\head.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0;
        int far = 0;
        int jumps = 0;

        for (int i = 0; i < n - 1; i++) {
            // 更新所能到达的最远位置
            far = max(far, i + nums[i]);
            // 到达当前能到达的最远位置的末尾时，更新跳跃次数和最远位置的末尾
            if (end == i) {
                jumps++;
                end = far;
            }
        }
        return jumps;
    }
};