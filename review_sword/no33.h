/*
no.33 
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接触所有书中最小的一个。
例如输入数组{3，32，321}，则打印处这三个数字能组成的最小数字为321323。
把只包含质因子2、3和5的数称作丑数。
*/

#include "..\head.h"

int GetUglyNum_Solution(int index) {
    if (index < 7) 
        return index;
    vector<int> res(index, 0);
    res[0] = 1;
    int index2 = 0;
    int index3 = 0;
    int index5 = 0;
    for (int i = 1; i < index; ++i) {
        int minNum = min(min(res[index2] * 2, res[index3] * 3), res[index5] * 5);
        if (minNum == res[index2] * 2)
            index2++;
        if (minNum == res[index3] * 3)
            index3++;
        if (minNum == res[index5] * 5)
            index5++;
        res[i] = minNum;
    }
    return res[index - 1];
}