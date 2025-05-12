#include "..\..\head.h"

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (typed.size() < name.size())
            return false;

        int name_len = name.size();
        int type_len = typed.size();
        int i = 0, j = 0;
        while (i < name_len && j < type_len) {
            if (name[i] == typed[j]) {
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        if (i == name_len && j <= type_len) {
            return true;
        } else {
            return false;
        }
    }
};

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while (j < typed.size()) {
            if (i < name.length() && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == name.length();
    }
};