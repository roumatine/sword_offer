#include "..\head.h"

int jumpfloor(int num) {
    if (num == 1) 
        return 1;
    if (num == 2) 
        return 2;

    return jumpfloor(num - 1) + jumpfloor(num - 2);
}

int jumpFloor(int n) {
    if (n == 1) {
        return 1;
    }
    int first = 1;
    int second = 2;
    for (int i = 3; i <= n; ++i) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}