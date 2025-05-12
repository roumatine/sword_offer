#include "..\..\head.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        if (x <= 3)
            return 1;
        int min = 0;
        int max = x;
        while (max - min > 1) {
            int m = (min + max) / 2;
            if (x / m < m) {
                max = m;
            } else {
                min = m;
            }
        }
        return min;
    }
};