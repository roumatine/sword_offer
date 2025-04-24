/*
No.7 斐波那契
*/

#include "..\head.h"
int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    if (n == 3) {
        return 2;
    }
    vector<int> f(3);
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; ++i) {
        f[i % 3] = f[(i - 1) % 3] + f[(i - 2) % 3];
    }
    return f[(i - 1) % 3]; 
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int first = 0;
    int second = 1;
    int third = 1;
    for (int i = 2; i <= n; ++i) {
        third = first + second;
        first = second;
        second = third;
    }
    return third;
}

int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    } 
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}