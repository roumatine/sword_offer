#include "..\head.h"

bool isEven(int n) {
    return (n & 1) == 0;
}

void Reorder(int *pData, unsigned int len, bool (*func)(int)) {
    if (pData == nullptr || len == 0) {
        return;
    }

    int *pBegin = pData;
    int *pEnd = pData + len - 1;
    while (pBegin < pEnd) {
        while (pBegin < pEnd && !func(*pBegin)) {
            pBegin++;
        }
        while (pBegin < pEnd && func(*pEnd)) {
            pEnd--;
        }

        if (pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

void ReorderEven(int *pData, unsigned int len) {
    Reorder(pData, len, isEven);
}