#include "..\..\head.h"


// class Solution {
// public:
//     bool buddyStrings(string s, string goal) {
//         if (s.size() != goal.size())
//             return false;
//         if (s == goal) {
//             unordered_set<char> charSet;
//             for (char c : s) {
//                 if (charSet.count(c))
//                     return true;
//                 charSet.insert(c);
//             }
//             return false;
//         }
//         vector<int> diff;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] != goal[i]) {
//                 diff.push_back(i);
//             }
//         }
//         if (diff.size() != 2) {
//             return false;
//         }
//         return s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
//     }
// };

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size() || s.size() < 2)
            return false;
        int len = s.size();
        vector<int> vec;
        vec.reserve(len);
        for (int i = 0; i < len; ++i) {
            if (s[i] != goal[i]) {
                vec.push_back(i);
                if (vec.size() > 2)
                    return false;
            }
        }
        if (vec.size() == 0) {
            unordered_set<char> unset(s.begin(), s.end());
            return unset.size() < len;
        }
        return s[vec[0]] == goal[vec[1]] && s[vec[1]] == goal[vec[0]];
    }
};