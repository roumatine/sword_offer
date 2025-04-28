/*
no.41 和为S的连续整数序列
输出所有和为S的连续正数序列。
序列内按照从小至大的顺序，序列见按照开始数字从小到大的顺序
*/

#include "..\head.h"

vector<vector<int>> FindContinuousSequence(int sum) {
    vector<vector<int>> res;
    int low = 1;
    int high = 2;
    while (low < high) {
        int sumTmp = (low + high) * (high - low + 1) / 2;
        if (sum == sumTmp) {
            vector<int> tmp;
            for (int i = low; i <= high; ++i) {
                tmp.push_back(i);
            }
            res.push_back(std::move(tmp));
            low ++;
        } else if (sumTmp < sum) {
            high ++;
        } else {
            low ++;
        }
    }
    return std::move(res);
}