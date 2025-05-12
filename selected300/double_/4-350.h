#include "..\..\head.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> vec;
        int index1 = 0, index2 = 0;
        while (index1 < len1 && index2 < len2) {
            if (nums1[index1] < nums2[index2]) {
                index1 ++;
            } else if (nums1[index1] > nums2[index2]) {
                index2 ++;
            } else {
                vec.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        }
        return vec;
    }
};

// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         if (nums1.size() > nums2.size()) {
//             return intersect(nums2, nums1);
//         }
//         unordered_map<int, int> unmp;
//         for (auto num : nums1) {
//             ++unmp[num];
//         }
//         vector<int> vec;
//         for (auto num : nums2) {
//             if (unmp.count(num)) {
//                 vec.push_back(num);
//                 --unmp[num];
//                 if (unmp[num] == 0) {
//                     unmp.erase(num);
//                 }
//             }
//         }
//         return vec;
//     }
// };

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int>::iterator it;
        for (int i = 0; i < nums1.size(); ++i) {
            it = find(nums2.begin(), nums2.end(), nums1[i]);
            if (it != nums2.end()) {
                res.push_back(*it);
                nums2.erase(it);
            }
        }
        return res;
    }
};