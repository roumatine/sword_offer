#include "..\..\head.h"

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = toSum(slow);
            fast = toSum(fast);
            fast = toSum(fast);
        } while (slow != fast);
        return slow == 1;
    }
private:
    int toSum(int n) {
        int sum = 0;
        while (n > 0) {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        
    }
};

class Solution {
public:
    bool isHappy(int n) {
        
    }
};