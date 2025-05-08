#include "..\..\head.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int a1 = 0, b1 = 0;
        int plus = 0;
        while (a1 < a.size() || b1 < b.size()) {
            int a2 = 0;
            int b2 = 0;
            if (a1 < a.size()) {
                a2 = a[a1] - '0';
                ++a1;
            }
            if (b1 < b.size()) {
                b2 = b[b1] - '0';
                ++b1;
            }
            ans += ((plus + a2 + b2) & 1) + '0';
            plus = (plus + a2 + b2) >> 1;
        }
        if (plus) {
            ans  += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};