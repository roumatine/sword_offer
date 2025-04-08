#include "..\head.h"

// =====solution1=====

bool IsUgly(int num) {
    while (num % 2 == 0) {
        num /= 2;
    }
    while (num % 3 == 0) {
        num /= 3;
    }
    while (num % 5 == 0) {
        num /= 5;
    }
    return (num == 1) ? true : false;
}

int getUglyNumber(int index) {
    if (index <= 0) {
        return 0;
    }
    int count = 0;
    int num = 0;
    while (count < index) {
        num++;
        if (IsUgly(num)) {
            count++;
        }
    }
    return num;
}

// =====solution2=====

int Min(int num1, int num2, int num3) {
    int min = (num1 < num2) ? num1 : num2;
    min = (min < num3) ? min : num3;

    return min;
}


int getUglynum_solution2(int index) {
    if (index <= 0) {
        return 0;
    }

    int *Uglynums = new int[index];
    Uglynums[0] = 1;
    int next_index = 1;

    int *multiply2 = Uglynums;
    int *multiply3 = Uglynums;
    int *multiply5 = Uglynums;

    while (next_index < index) {
        int min = Min(*multiply2 * 2, *multiply3 * 3, *multiply5 * 5);
        Uglynums[next_index] = min;

        while (*multiply2 * 2 <= Uglynums[next_index]) {
            multiply2++;
        }
        while (*multiply3 * 3 <= Uglynums[next_index]) {
            multiply3++;
        }
        while (*multiply5 * 5 <= Uglynums[next_index]) {
            multiply5++;
        }
        next_index++;
    }
    int ugly = Uglynums[next_index - 1];
    delete[] Uglynums;
    return ugly;
}