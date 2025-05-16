#include "..\..\head.h"

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        vector<int> pw(n, 0);
        pw[0] = 1;
        for (int i = 1; i < n; i++) {
            pw[i] = (pw[i - 1] * 2 ) % mod;
        }
        for (int i = 0, j = n - 1; i < n; i++) {
            while (i <= j && nums[i] + nums[j] > target) {
                j --;
            }
            if (i > j)
                break;
            res = (res + pw[j - i]) % mod;
        }
        return res;
    }
};