#include "..\head.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                nums[slow] = nums[fast];
                slow++;
            } else {
                fast ++;
            }
        }
        return slow + 1;
    }
};
