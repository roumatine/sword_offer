/*
no.49 字符串转化为整数
将一个字符串转换成一个整数，要求不能使用字符转换的库函数。
数值为0或者字符串不是一个合法的数值则返回0
*/

#include "..\head.h"

int StrToInt(string str) {
    int len = str.size();
    if (len == 0)
        return 0;
    int i = 0, flag = 1, isSignal = 0;
    long res = 0;
    while (i < len && str[i] == ' ') {
        i++; // 跳过空格
    }
    if (i >= len )
        return 0; // 排除全空格

    while (i < len && (str[i] == '-' || str[i] == '+')) {
        if (str[i] == '-')
            flag = -1;
        i++;
        isSignal ++;
        if (isSignal > 1)
            return 0;
    }
    for (; i < len; ++i) {
        if(str[i] > '9' || str[i] < '0')
            return 0;
        res = res * 10 + str[i] - '0';
        if (res > INT_MAX && flag == 1)
            return 0;
        if (res - 1 > INT_MAX && flag == -1)
            return 0;
    }
    return flag * res;
}