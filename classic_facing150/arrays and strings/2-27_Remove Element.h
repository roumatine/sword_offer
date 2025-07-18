#include "..\head.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 初始化一个“栈顶”指针，用于指示下一个要放置元素的位置
        int stk = 0;
        // 遍历数组中的每个元素
        for (int i : nums) {
            // 如果当前元素不等于需要移除的值
            if (i != val) {
                nums[stk++] = i;
            }
        }
        return stk;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         // 获取数组长度
        int n = nums.size();
        // 初始化左指针
        int left = 0;
        // 遍历数组
        for (int right = 0; right < n; right++) {
            // 如果当前元素不等于指定值
            if (nums[right] != val) {
                // 将当前元素移动到左指针位置
                nums[left] = nums[right];
                // 左指针向前移动
                left++;
            }
        }
        return left;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 初始化快慢指针
        int fast = 0;
        int slow = 0;
         // 遍历数组，直到快指针到达数组末尾
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast]; 
                // 先给 nums[slow] 赋值然后再给 slow++
                // 这样可以保证 nums[0..slow-1] 是不包含值为 val 的元素的，最后的结果数组长度就是 slow
                slow++;
            }
            // 移动快指针，继续遍历数组
            fast++;
        }
        // 返回慢指针的位置，即为移除指定元素后的数组长度
        return slow;
    }
};
