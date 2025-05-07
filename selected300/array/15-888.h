#include "..\..\head.h"

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int size1 = aliceSizes.size();
        int size2 = bobSizes.size();
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int target = (sumA - sumB) / 2;
        sort(bobSizes.begin(), bobSizes.end());
        for (int a : aliceSizes) {
            int b = a - target;
            if (binary_search(bobSizes.begin(), bobSizes.end(), b)) {
                return {a, b};
            }
        }
        return {};
    }
};


// class Solution {
// public:
//     vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
//         int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
//         int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
//         int diff = (sumB - sumA) / 2;
//         unordered_set<int> s(aliceSizes.begin(), aliceSizes.end());
//         vector<int> ans;
//         for (auto& b : bobSizes) {
//             int B = b + diff;
//             if (s.count(B)) {
//                 ans = vector<int> {x, y};
//                 break;
//             }
//         }
//         return ans;
//     }
// };