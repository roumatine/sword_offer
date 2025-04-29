/*
no.54 字符流中第一个不重复的字符
*/
#include "..\head.h"

class Solution {
public:
    vector<char> v;
    unordered_map<char, int> unmp;
    void Insert(char ch) {
        v.push_back(ch);
        unmp[ch] ++;
    }
    char FirstAppearingOnce() {
        for (auto &ch : v) {
            if (unmp[ch] == 1)
                return ch;
        }
        return '#';
    }
};