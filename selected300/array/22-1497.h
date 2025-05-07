#include "..\..\head.h"

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        for (auto a : arr) {
            res[(a % k + k) % k] ++;
        }
        if (res[0] % 2 != 0)
            return false;
        for (int i = 1; i <= k / 2; ++i) {
            if (res[i] != res[k - i])
                return false;
        }
        return true;
    }
};