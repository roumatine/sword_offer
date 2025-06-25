#include "..\..\head.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int slow = 0, fast = n - 1;

        for (int i = 0; i < n; i++) {
            if (numbers[slow] + numbers[fast] == target) {
                if (slow == fast) {
                    break;
                }
                return {slow + 1, fast + 1};
            } else if (numbers[slow] + numbers[fast] > target) {
                fast--;
            } else if (numbers[slow] + numbers[fast] < target) {
                slow ++;
            }
        }
        return {};
    }
};