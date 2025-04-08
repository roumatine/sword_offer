#include "..\head.h"

bool g_InvalidInput = false;

int FindGreatSumOfSubArra(int *pdata,int nlen) {
    if ((pdata == nullptr) || (nlen <= 0)) {
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    int cur_sum = 0;
    int great_sum = 0x80000000; // 记录连续子数组的最大和,初始值设置为很小的负数
    for (int i = 0; i < nlen; ++i) {
        if (cur_sum <= 0) {
            cur_sum = pdata[i];
        } else {
            cur_sum += pdata[i];
        }
        if (cur_sum > great_sum) {
            great_sum = cur_sum;
        }
    }
    return great_sum;
}