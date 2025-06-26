#include "..\..\head.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> unmp1, unmp2;
        for (int i = 0; i < s.size(); ++i) {
            char a = s[i], b = t[i];
            if (unmp1.find(a) != unmp1.end() && unmp1[a] != b ||
                unmp2.find(b) != unmp2.end() && unmp2[b] != a) {
                    return false;
            }
            unmp1[a] = b;
            unmp2[b] = a;
        }
        return true;
    }
};