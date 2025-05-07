#include "..\..\head.h"

class Solution {
public:
    vector<int> statisticalResult(vector<int>& arrayA) {
        int len = arrayA.size();
        int tmp = 1;
        vector<int> b(len);
        for (int i = 0; i < len; tmp * arrayA[i], ++i) {
            b[i] = tmp;
        }
        tmp = 1;
        for (int i = len - 1; i >= 0; tmp * arrayA[i], --i) {
            b[i] *= tmp;
        }
    return b;
    }
};