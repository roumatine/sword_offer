#include "..\..\head.h"


// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//         string s = a;
//         while (s.size() <= b.size()) {
//             s += a;
//         }
//         s += a;
//         size_t found = s.find(b);
//         if (found == string::npos)
//             return -1;
//         return (b.size() + found - 1) / a.size() + 1;
//     }
// };


class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (a.empty()) 
            return -1;
        string s = a;
        int i = 1;
        while (s.size() < b.size()) {
            s.append(a);
            ++i;
        }
        if (s.find(b) != string::npos) {
            return i;
        }
        s.append(a);
        ++i;
        if (s.find(b) != string::npos) {
            return i;
        }
        return -1;
    }
};