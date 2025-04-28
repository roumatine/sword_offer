#include "..\head.h"

int NumberOf1Between1AndN_Solution(int n) {
    if (n <= 0)
        return 0;
    if (n < 10)
        return 1;
    int high = n;
    int pow = 1;
    while (high >= 10) {
        high /= 10;
        pow *= 10;
    }
    int last = n - high * pow;
    int cnt = high == 1 ? last + 1 : pow;
    return cnt + high * NumberOf1Between1AndN_Solution(pow - 1) + NumberOf1Between1AndN_Solution(last);
}

int num_of1_between1_andn_solution(int n) {
    if (n <= 0)
        return 0;
    if (n < 10)
        return 1;
    int high = n;
    int pow = 1;
    while (high >= 10) {
        high /= 10;
        pow *= 10;
    }
    int last = n - high * pow;
    int cut = (high == 1 ? last + 1 : pow);
    return cnt + high * NumberOf1Between1AndN_Solution(pow - 1) + NumberOf1Between1AndN_Solution(last);
}