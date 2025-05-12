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
        }
    }
};