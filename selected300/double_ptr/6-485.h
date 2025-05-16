#include "..\..\head.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cnt ++;
            } else {
                maxCnt = max(maxCnt, cnt);
                cnt = 0;
            }
        }
        maxCnt = max(maxCnt, cnt);
        return maxCnt;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && nums[j] == 1)
                j++;
            res = max(res, j - i);
            i = j;
        }
        return res;
    }
};
