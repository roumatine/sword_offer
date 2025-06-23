#include "..\head.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int fast = 0;
        int slow = 0;
        int cnt = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                // 此时，对于 nums[0..slow] 来说，nums[fast] 是一个新的元素，加进来
                slow++;
                nums[slow] = nums[fast];
                
            } else if (slow < fast && cnt < 2) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
            cnt ++;
            if (fast < nums.size() && nums[fast] != nums[fast - 1]) {
                cnt = 0;
            }

        }
        return slow + 1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n; // 长度小于等于 2 的数组无需处理
        }
        int slow = 2, fast = 2; // 初始两个指针都从第三个元素开始
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                 // 当前元素与前面倒数第二个元素不同，表示不重复
                nums[slow] = nums[fast]; // 将该元素复制到慢指针位置
                ++slow; // 慢指针前进
            }
            ++fast;
        }
        return slow;
    }
};