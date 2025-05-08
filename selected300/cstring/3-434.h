#include "..\..\head.h"

// class Solution {
// public:
//     int countSegments(string s) {
//         string str;
//         int cnt = 0;
//         stringstream ss;
//         ss << s;
//         while (ss >> str) {
//             cnt++;
//         }
//         return count;
//     }
// };


class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                cnt ++;
            }
        }
        return cnt;
    }
};