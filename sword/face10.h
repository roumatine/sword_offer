#include "..\head.h"

int NumberOf1_Solution1(int n) {
    int count = 0;
    unsigned int flag = 1;
    while(flag) {
        if (n & flag) { // 判断flag位是否为1
            count ++;
        }
        flag = flag << 1;
    }
    return count;
}

int NumberOf1_Solution2(int n) {
    int count = 0;
    while (n)
    {
        /* code */
        ++ count;
        n = (n - 1) & n;
    }
    return count;
}