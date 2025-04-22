/*
No.2 替换空格
*/

#include "..\head.h"

void replaceSpace(char *str, int len) {
    int spaceCount = 0;
    int totallen = len;
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }
    totallen += spaceCount * 2;
    for (int i = len - 1; i >= 0 && totallen != i; i--) {
        if (str[i]!= ' ') {
            str[--totallen] = str[i]; // 注意这里要先--，否则会覆盖掉str[i]
        } else {
            str[--totallen] = '0';
            str[--totallen] = '2';
            str[--totallen] = '%';
        }
    }
}