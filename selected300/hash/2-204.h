#include "..\..\head.h"
class Solution {
public:
    int countPrimes(int n) {
        vector<int> a(n);
        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            a[i] = 1;
        }
        for (int i = 2; i < n; ++i) {
            if (a[i]) {
                cnt ++;
                for (int j = 2 * i; j < n; j += i) {
                    a[j] = 0;
                }
            }
        }
        return cnt;
    }
};