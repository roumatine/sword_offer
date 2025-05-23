/*
no.47 求1+2+3+...+n
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
*/
#include "..\head.h"

int sum_solution(int n) {
    bool a[n][n + 1];
    return sizeof(a) >> 1;
}

int Sum_Solution(int n) {
    int sumNum = n;
    bool ans = (n > 0) && ((sumNum += Sum_Solution(n - 1)) > 0);
    return sumNum;
}