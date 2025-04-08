#include "..\head.h"

const int Max_Num_len = 10;

char *Str_Combine1 = new char[Max_Num_len * 2 + 1];
char *Str_Combine2 = new char[Max_Num_len * 2 + 1];

int compare(const void *strNum1, const void* strNum2) {
    strcpy(Str_Combine1, *(char**)strNum1);
    strcat(Str_Combine1, *(char**)strNum2);

    strcpy(Str_Combine2, *(char**)strNum2);
    strcat(Str_Combine2, *(char**)strNum1);

    return 0;
}

void Print_Min_Num(const int *nums, int len) {
    if (nums == nullptr || len <= 0) {
        return;
    }
    char **strNums = (char**)(new int[len]);
    for (int i = 0; i < len; ++i) {
        strNums[i] = new char[Max_Num_len + 1];
        sprintf(strNums[i], "%d", nums[i]);
    }

    qsort(strNums, len, sizeof(char*), compare);

    for (int i = 0; i < len; ++i) {
        printf("%s", strNums[i]);
    }
    printf("\n");

    for (int i = 0; i < len; ++i) {
        delete[] strNums[i];
    }
    delete strNums;
}