#include "..\..\head.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j ++;
        }
        return i == s.size();
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) {
            return true;
        }

        for (int i = 0, j = 0; j < t.size(); j ++) {
            if (s[i] == t[j]) {
                i++;
            }
            if (i == s.size()) {
                return true;
            }
        }
        return false;
    }
};