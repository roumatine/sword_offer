#include "..\..\head.h"

class Solution1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = n + 1;
        int sum = 0, left = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }
            if (sum >= target) {
                res = min(res, right - left + 1);
            }
        }
        return res <= n ? res : 0;
    }
};

class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = n + 1;
        int sum = 0, left = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left ++;
            }
        }
        return res <= n ? res : 0;
    }
};


// 有些是在内部循环外面最后更新最优解(第一种解法)
// 有些窗口是在内部循环里更新最优解(第2种解法),
// 前者是内部循环一直不满足条件(本题就是发现减掉left还是比sum大说明现在不是最优解),
// 该解法在循环外更新最优解, 这个的前提条件是,窗口仅一个元素的时候一定是一个解(不一定最优)
// 后者是循环内部都满足条件,不断缩小窗口得到最优解, ,缩小窗口直到满足退出循环