#include "..\..\head.h"

class Solution {
public :
    int maxDistToClosest(vector<int> &seats) {
        int res = 0;
        int len = 0;
        while (len < seats.size() && seats[len] == 0) {
            ++len;
        }
        res = max(res, len);
        while (len < seats.size()) {
            int r = len + 1;
            while (r < seats.size() && seats[r] == 0) {
                ++r;
            }
            if (r == seats.size()) {
                res = max(res, r - len - 1);
            } else {
                res = max(res, (r - len) / 2);
            }
            len = r;
        }
        return res;
    }
};