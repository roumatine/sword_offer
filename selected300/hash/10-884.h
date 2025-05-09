#include "..\..\head.h"

// class Solution {
// public:
//     vector<string> uncommonFromSentences(string s1, string s2){
//         unordered_map<string, int> unmp;
//         stringstream ss;
//         ss << s1 << " " << s2;
//         string s;
//         while (ss >> s) {
//             ++unmp[s];
//         }
//         vector<string> ans;
//         for (auto & [s,c] : unmp) {
//             if (c == 1)
//                 ans.emplace_back(move(s));
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> unmp;
        
        string tmp;
        for (int i = 0; i < s1.size(); ++i) {
            tmp = "";
            while (s1[i] != ' ' && i < s1.size()) {
                tmp += s1[i++];
            }
            if (tmp.size() > 0) {
                ++unmp[tmp];
            }
        }
        for (int i = 0; i < s2.size(); ++i) {
            tmp = "";
            while (s2[i] != ' ' && i < s2.size()) {
                tmp += s2[i++];
            }
            if (tmp.size() > 0) {
                ++unmp[tmp];
            }
        }
        vector<string> vec;
        for (auto &a : unmp) {
            if (a.second == 1) 
                vec.push_back(a.first);
        }
        return vec;
    }    
};