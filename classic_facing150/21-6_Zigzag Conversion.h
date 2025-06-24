#include "..\head.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        vector<string> rows(numRows);
        int i = 0;
        int flag = -1;
        for (char c : s) {
            rows[i].push_back(c);
            if (i == numRows - 1 || i == 0) {
                flag = -flag;
            }
            i += flag;
        }
        string res;
        for (const string &row : rows) {
            res += row;
        }
        return res;
    }
};


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int step = 2 * numRows - 2;
        int index = 0;
        int len = s.size();
        int add = 0;
        string res;
        for (int i = 0; i < numRows; i++) {
            index = i;
            add = 2 * i;
            while (index < len)
            {
                res += s[index];
                add = step - add;
                index += (i == 0 || i == numRows - 1) ? step : add;
            }
        }
        return res;
    }
};