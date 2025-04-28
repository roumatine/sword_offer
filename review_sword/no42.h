/*
no.42 和为S的两个数字
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S,输出两个数的乘积最小的。
*/


#include "..\head.h"

vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    vector<int> res;
    if (array.size() == 0) 
        return res;

    int low = 0;
    int high = array.size() - 1;
    while (low < high) {
        if (array[low] + array[high] == sum) {
            res.push_back(array[low]);
            res.push_back(array[high]);
            return res;
        } else if (array[low] + array[high] < sum) {
            low ++;
        } else {
            high --;
        }
    }
    return res;
}