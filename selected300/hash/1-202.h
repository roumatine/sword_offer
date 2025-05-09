#include "..\..\head.h"

// class Solution {
// public:
//     int bitSquareSum(int n) {
//         int sum = 0;
//         while (n > 0) {
//             int bit = n % 10;
//             sum += bit * bit;
//             n /= 10;
//         }
//         return sum;
//     }
//     bool isHappy(int n) {
//         int slow = 0;
//         int fast = 0;
//         do {
//             slow = bitSquareSum(slow);
//             fast = bitSquareSum(fast);
//             fast = bitSquareSum(fast);

//         }while(slow != fast);
//         return slow == 1;
//     }
// };

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) 
            return false;
        unordered_set<int> s;
        int sum = 0;
        while (n != 1) {
            sum = 0;
            while (n > 9) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            sum += n * n;
            if (s.find(sum) != s.end())
                return false;
            else 
                s.insert(sum);
            n = sum;
        }
        return true;
    }
};