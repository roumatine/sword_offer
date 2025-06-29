#include "..\..\head.h"


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> unmp;
        if (s.size() != t.size()) {
            return false;
        }

        for (char c : s) {
            unmp[c] += 1;
        }
        for (char c : t) {
            unmp[c] -= 1;
        }
        for (auto b : unmp) {
            if (b.second != 0) {
                return false;
            }
        }
        return true;
    }
};