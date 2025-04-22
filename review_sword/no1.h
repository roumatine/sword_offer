/*
No.1 二维数组中的查找

在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数

[
[1,2,8,9],
[2,4,9,12],
[4,7,10,13],
[6,8,11,15]
]

*/

#include "..\head.h"

bool Find(int target, vector<vector<int>> array) {
    if (array.size() == 0 || array[0].size() == 0) {
        return false;
    }
    int row = array.size(); // 行数
    int col = array[0].size(); // 列数
    int w = col - 1; // 从右上角开始
    int h = 0;
    while (w >= 0 && h < row) { // 边界条件
        if (array[h][w] > target) {
            w --;
        } else if (array[h][w] < target) {
            h ++;
        } else {
            return true;
        }
    }
    return false;
}

