#include "..\head.h"

int jumpFloorII(int num) {
    if (num == 1) 
        return 1;
    return 2 * jumpFloorII(num - 1);
}

int jumpFloorII2(int number) {
    if (number == 1)
        return 1;

    int count = 0;
    int a = 1;
    for (int i = 2; i <= number; ++i) {
        count = a * 2;
        a = count;
    }
    return count;
}

if jumpFloorII3(int num) {
    if (num <= 1) 
        return num;
    return pow(2, num - 1);
}