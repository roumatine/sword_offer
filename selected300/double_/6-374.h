#include "..\..\head.h"

class Solution {
int guess(int num);
public:
    int guessNumber(int n) {
        int low = 1;
        int mid = low + (n - low) / 2;
        while (low < n) {
            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == 1)
                low = mid + 1;
            else 
                n = mid - 1;
            mid = low + (n - low) / 2;
        }
        return low;
    }
};

class Solution {
int guess(int num);
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (guess(mid) <= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};