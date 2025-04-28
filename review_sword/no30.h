#include "..\head.h"

int FindGreatestSumOfSubArray(vector<int> array) {
    for (int i = 1; i < array.size(); ++i) {
        array[i] = max(0, array[i - 1] + array[i]);
    }
    return *max_element(array.begin(), array.end());
}

int find_greatest_sum_of_sub_array(vector<int> array) {
    int len = array.size();
    int maxNum = array[0];
    int res = maxNum;
    for (int i = 1; i < len; ++i) {
        if (maxNum + array[i] > array[i]) {
            maxNum += array[i];
        } else {
            maxNum = array[i];
        }
        res = max(res, maxNum);
    }
    return res;
}