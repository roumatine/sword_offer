/*
no.67 剪绳子
*/

#include "..\head.h"

int cutRope(int num) {
    if (num == 2) {
        return 1;
    }
    if (num == 3) {
        return 2;
    }
    int x = num % 3;
    int y = num / 3;
    if (x == 0) {
        return pow(3, y);
    } else if (x == 1) {
        return 2 * 2 * pow(3, y - 1);
    } else {
        return 2 * pow(3, y);
    }
}

int cuttingRope(int n) {
    if (n < 2)
        return 0;
    if (n < 4)
        return n - 1;
    int maxNum = 1;
    while (n > 4) {
        maxNum *= 3;
        n -= 3;
    }
    maxNum*=n;
    return maxNum;
}

int CuttingRope(int n) {
    if (n < 2)
        return 0;
    if (n < 4)
        return n - 1;
    long maxNum = 1;
    long mod = 1000000007;
    while (n > 4) {
        maxNum *= 3;
        maxNum %= mod;
        n -= 3;
    }
    maxNum *= n;
    maxNum %= mod;
    return maxNum;
}