#include "..\..\head.h"

class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        if (len == 0) 
            return 0;
        int i = 0;
        int flag = 1;
        int isSingal = 0;
        long res = 0;
        while (i < len && s[i] == ' ')
            i ++;
        if (i >= len)
            return 0;
        if (i < len && s[i] == '-') {
            flag = -1;
            ++i;
            ++isSingal;
        }
        if (isSingal > 1)
            return 0;
        for (; i < len && s[i] >= '0' && s[i] <= '9'; ++i) {
            res = res * 10 + (s[i] - '0');
            if (res >= INT_MAX && flag == 1)
                return INT_MAX;
            if (res > INT_MAX && flag == -1)
                return INT_MIN;
        }
        return flag * res;
    }
};


class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int bndry = INT_MAX / 10;
        int i = 0;
        int sign = 1;
        int len = s.size();
        if (len == 0)
            return 0;
        while (s[i] == ' ') {
            if (++i = len)
                return 0;
        }
        if (s[i] == '-')
            sign = -1;
        if (s[i] == '-' || s[i] == '+')
            i++;
        for (int j = i; j < len; j ++) {
            if (s[j] < '0' || s[j] > '9')
                break;
            if (res > bndry || res == bndry && s[j] > '7') {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + (s[j] - '0');
        }
        return sign * res;
    }
};