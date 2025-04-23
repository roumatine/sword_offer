/*
No.6旋转数组的最小数字
有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组
比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值
note:给出的所有元素都大于0，若数组大小为0则返回0
*/

#include "..\head.h"

int minNumInRotateArray(vector<int> &rotateArray) {
    if (rotateArray.size() == 0) {
        return 0;
    }
    int minNum = rotateArray[0];
    int len = rotateArray.size();
    for (int i = 0; i < len - 1; ++i) {
        if (rotateArray[i] > rotateArray[i + 1]) {
            return rotateArray[i + 1];
        }
    }
    return rotateArray[0];
}

// 二分法

int minNumInRotateArray_i(vector<int> &rotateArray) {
    if (rotateArray.size() == 0) {
        return 0;
    }
    int low = 0;
    int high = rotateArray.size() - 1;
    while (low + 1 < high) {
        int mid = low + (high - low) / 2;
        if (rotateArray[mid] < rotateArray[high]) {
            high = mid;
        } else if (rotateArray[mid] == rotateArray[high]) {
            high = high - 1;
        } else {
            low = mid;
        }
    }
    return min(rotateArray[low], rotateArray[high]);
}