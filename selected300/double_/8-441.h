#include "..\..\head.h"

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if ((long long)mid * (mid + 1) <= (long long)2 * n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

// class Solution {
// public:
//     int arrangeCoins(int n) {
//         return (int) ((sqrt((long long)8 * n + 1)- 1) / 2);
//     }
// }; 

class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int sum = 0;
        while (n - i >= 0) {
            sum ++;
            n= n - i;
            i ++;
        }
        return sum;
    }
};