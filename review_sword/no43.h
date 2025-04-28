/*
no.43 左旋转字符串
*/

#include "..\head.h"

string LeftRotateString(string str, int n) {
    int len = str.size();
    if (len == 0)
        return str;
    
    if (n >= len)
        n = n % len;
    
    str += str;
    return str.substr(n, len);
}