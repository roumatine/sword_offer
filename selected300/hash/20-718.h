#include "..\..\head.h"

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int maxNum = 0;
        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = nums1[i] == nums2[j] ? 1 : 0;
                } else {
                    if (nums1[i] == nums2[j]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        maxNum = max(maxNum, dp[i][j]);
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return maxNum;
    }
};