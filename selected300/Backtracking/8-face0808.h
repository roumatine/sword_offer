#include "..\..\head.h"

class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> res;
        sort(S.begin(), S.end());
        do {
            res.push_back(S);
        } while (next_permutation(S.begin(), S.end()));
        return res;
    }
};