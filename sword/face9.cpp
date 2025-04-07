
#include "face9.h"


long long Fibonacci_solution1(unsigned int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return Fibonacci_solution1(n - 1) + Fibonacci_solution1(n - 2);
}
long long Fibonacci_solution2(unsigned int n) {
    int result[2] = {0, 1};
    if (n <2) {
        return result[2];
    }
    long long fibOne = 0;
    long long fibTwo = 1;
    long long fibplus = 0;
    for (unsigned int i = 2; i <= n; i++) {
        fibplus = fibOne + fibTwo;

        fibTwo = fibOne;
        fibOne = fibplus;
    }
    return fibplus;
}

oid Test(int n, int expected)
{
    if(Fibonacci_solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if(Fibonacci_solution2(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

    if(Fibonacci_Solution3(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);
}

int main(int argc, char* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}