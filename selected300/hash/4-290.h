#include "..\..\head.h"


// class Solution {
// public:
//     bool wordPattern(string pattern, string s) {
//         unordered_map<char, string> unmp1;
//         unordered_map<string, char> unmp2;
//         stringstream ss(s);
//         string str;
//         for (char c : pattern) {
//             if (!(ss >> str) || (unmp1.count(c) && unmp1[c] != str) ||
//                 (unmp2.count(str) == 1 && unmp2[str] != c)) {
//                     return false;
//                 }
//             unmp1[c] = str;
//             unmp2[str] = c;
//         }
//         return (ss >> str) ? false : true;
//     }
// };

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> unmp1;
        unordered_map<string, int> unmp2;
        string tmp = "";
        int a = 1;
        unsigned i, j;
        for (i = 0, j = 0; i < pattern.size() && j < str.size(); i++, j++) {
            tmp = "";
            unmp1[pattern[i]] += i + a;
            while (str[j] != ' ' && j < str.size()) {
                tmp += str[j++];
            }
            unmp2[tmp] += i + a;
            if (unmp1[pattern[i]] != unmp2[tmp])
                return false; 
        }
        return i == pattern.size() && j == str.size();
    }
};