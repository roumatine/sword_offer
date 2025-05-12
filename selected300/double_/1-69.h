#include "..\..\head.h"

class Solution {
public:
    int mySqrt(int x) {
        long mid = 0;
        long left = 0;
        long right = x;
        while (left < right) {
            mid = (left + right + 1) / 2;
            long sq = mid * mid;
            if (sq > x) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return (int)left;
    }
};