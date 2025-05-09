#include "..\..\head.h"

// class Solution {
// public:
//     vector<int> powerfulIntegers(int x, int y, int bound) {
//         unordered_set<int> unset;
//         for (int i = 0; i < 20 && pow(x ,i) <= bound; ++i) {
//             for (int j = 0; j < 20 && pow(y, j) <= bound; ++j) {
//                 int v = int(pow(x, i) + pow(y, j));
//                 if (v <= bound)
//                     unset.insert(v);
//             }
//         }
//         vector<int> vec;
//         vec.assign(unset.begin(), unset.end());
//         return vec;
//     }
// };


class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> unset;
        for (int i = 1; i <= bound; i *=x) {
            for (int j = 1; i + j <= bound; j *= y) {
                unset.insert(i + j);
                if (y == 1) {
                    break;
                }
            }
            if (x == 1)
                break;
        }
        return vector<int>(unset.begin(), unset.end());
    }
};