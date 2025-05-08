#include "..\..\head.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) 
            return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        string res;
        for (string row : rows) {
            res += row;
        }
        return res;
    }
};


class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        int r =0;
        r = numRows;
        if (r == 1 || r >= n)
            return s;
        string ans;
        int t = r * 2 - 2;
        for (int i = 0; i < r; ++i) {
            for (int j = i; j < n; j += t) {
                ans += s[j + i];
                if (i > 0 && i < r - 1 && n > j + t - i) {
                    ans += s[j + t - i];
                }
            }
        }
        return ans;
    }
};