#include "..\..\head.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        t.insert(t.begin(), ' ');
        int len1 = s.size();
        int len2 = t.size();
        vector<vector<int>> dp(len2, vector<int>(26, 0));

        for (char c = 'a'; c <= 'z'; c++) {
            int next_pos = -1;
            for (int i = len2 - 1; i >= 0; i--) {
                dp[i][c - 'a'] = next_pos;
                if (t[i] == c) {
                    next_pos = i;
                }
            }
        }
        int index = 0;
        for (char c : s) {
            index = dp[index][c - 'a'];
            if (index == -1)
                return false;
        }
        return true;
    }
};