#include "..\head.h"

void PrintNumbr(char *num) {
    bool IsBegin = true;
    int nLen = strlen(num);
    for (int i = 0; i < nLen; i++) {
        if (IsBegin && num[i] != '0') {
            IsBegin = false;
        }
        if (!IsBegin) {
            std::cout << num[i] << " ";
        }
    }
}

void PrintToMaxOfDigitsRecursively(char *num, int len, int index) {
    if (index == len - 1) {
        PrintNumbr(num);
        return;
    }
    for (int i = 0; i < 10; i++) {
        num[index] = i + '0';
        PrintToMaxOfDigitsRecursively(num, len, index + 1);
    }
}

void PrintToMaxOfDigits(int n) {
    if (n <= 0) {
        return;
    }

    char *num = new char[n + 1];
    num[n] = '\0';

    for (int i = 0; i < 10; i++) {
        num[0] = i + '0';
        PrintToMaxOfDigitsRecursively(num, n, 0);
    }
    delete[] num;
}