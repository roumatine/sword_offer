#include "..\..\head.h"
 // 使用内置库函数
class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = (int) sqrt(num);
        return x * x == num;
    }
};

 // 不能使用任何内置的库函数，如 sqrt 

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long square = (long) mid * mid;
            if (square < (long)num) {
                left = mid + 1;
            } else if (square > (long)num) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};