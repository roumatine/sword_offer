#include "..\..\head.h"

class Solution {
bool isBadVersion(int version);
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) { // isBadVersion 题目提供
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};