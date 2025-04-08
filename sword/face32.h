#include "..\head.h"
// ================solution1=========================

int num_of_1(unsigned int n) {
    int num = 0;
    while (n) {
        if (n % 10 == 1) {
            num ++;
        }
        n = n/10;
    }
    return num;
}
int num_of_1_between1_and_solution1(unsigned int n) {
    int num = 0;
    for (unsigned int i = 0; i <=n; ++i) {
        num += num_of_1(i);
    }
    return num;
}

// ================solution2=========================
int Power_base_10(unsigned int n) {
    int result = 1;
    for (unsigned int i = 0; i < n; ++i) {
        result *= 10;
    }
    return result;
}

int Num_of_1(const char *strN) {
    if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')  {
        return 0;
    }
    int first = *strN - '0';
    unsigned int len = static_cast<unsigned int>(strlen(strN));

    if (len == 1 && first == 0) {
        return 0;
    }
    if (len == 1 && first > 0) {
        return 1;
    }

    int num_first_digit = 0;
    if (first > 1) {
        num_first_digit = Power_base_10(len - 1);
    } else if (first == 1) {
        num_first_digit = atoi(strN + 1) + 1;
    }

    int num_other_digits = first * (len - 1) * Power_base_10(len - 2);
    int num_recursive = Num_of_1(strN + 1);

    return num_first_digit + num_other_digits + num_recursive;
}

int num_of_1_between1_solution2(int n) {
    if (n <= 0) {
        return 0;
    }
    char strN[50];
    cout << strN << endl;

    return Num_of_1(strN);
}