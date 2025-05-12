#include "..\..\head.h"

class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for (char c : s) {
            if (!stk.empty() && stk.back() == c) {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        return stk;
    }
};

// string自己就可以做栈，string有pop和push接口