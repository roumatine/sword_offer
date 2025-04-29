/*
no.48 求两个数相加
写一个函数求两个整数之和，要求不能用四则运算
*/

#include "..\head.h"

int add(int num1, int num2) {
    while (num2 != 0) {
        int sum = num1 ^ num2;
        int carray = (num1 & num2) << 1;
        num1 = sum;
        num2 = carray;
    }
    return num1;
}