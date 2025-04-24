#include "..\head.h"

int jumpfloor(int num) {
    if (num == 1) 
        return 1;
    if (num == 2) 
        return 2;

    return jumpfloor(num - 1) + jumpfloor(num - 2);
}

