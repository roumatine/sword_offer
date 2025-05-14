#include "..\head.h"

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int len1 = strs.size();
        int len2 = strs[0].size();
        int res = 0;
        for (int i = 0; i < len2; ++i) {
            for (int j = 1; j < len1; ++j) {
                if (strs[j - 1][i] > strs[j][i]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};