/*
no.34 第一个只出现一次的字符
字符串中找到第一个只出现一次的字符，并返回它的位置，如果没有则返回-1
*/

#include "..\head.h"

int FirstNotRepeatingChar(string str) {
    unordered_map<char, int> mp;
    for (int i = 0; i < str.size(); i++) {
        mp[str[i]] += 1;
    }
    for (int i = 0; i < str.size(); i++) {
        if (mp[str[i]] == 1)
            return i;
    }
    return -1;
}