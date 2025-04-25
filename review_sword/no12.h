#include "..\head.h"

double Power(double base, int exponent) {
    if (exponent == 0)
        return 1.0;
    if (base == 0.0) 
        return 0.0;
    bool flag = false;
    if (exponent < 0) {
        flag = true;
        exponent *= -1;
    }
    double res = base;
    for (int i = 2; i <= exponent; ++i) {
        res *= base;
    }
    if (flag) 
        return 1.0 / res;
    else 
        return res;
}