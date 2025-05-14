#include "..\head.h"

class Solution {
public:
    int balancedStringSplit(string s) {
        int cntL = 0;
        int cntR = 0;
        int res = 0;
        for (auto &a : s) {
            if (a == 'L')
                cntL++;
            else
                cntR++;
            if (cntL == cntR)
                res++;
        }
        return res;
    }
};

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int d = 0;
        for (char ch : s) {
            ch == 'L' ? d++ : d--;
            if (d == 0)
                ans++;
        }
        return ans;
    }
};