#include "..\..\head.h"

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> unmp1, unmp2;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            char a = s[i], b = t[i];
            if ((unmp1.count(a)  && unmp1[a] != b) ||
                (unmp2.count(b)  && unmp2[b] != a)) {
                return false;
            }
            unmp1[a] = b;
            unmp2[b] = a;
        }
        return true;
}