#include "..\head.h"

void PrintMatrixInCircle(int **nums, int cols, int rows, int start) {
    int endX = cols - 1 - start;
    int endY = rows - 1 - start;

    // 从左到右打印一行
    for (int i = start; i <= endX; i++) {
        int num = nums[start][i];
        printNum(num);
    }

    // 从上到下打印一列
    if (start < endY) {
        for (int i = start + 1; i <= endY; ++i) {
            int num = nums[i][endX];
            printNum(num);
        }
    }

    // 从右到左打印一行
    if (start < endX && start < endY) {
        for (int i = endX - 1; i >= start; --i) {
            int num = nums[endY][i];
            printNum(num);
        }
    }

    // 从下到上打印一行
    if (start < endX && start < endY -1 ) {
        for (int i = endY - 1; i >= start + 1; --i) {
            int num = nums[i][start];
            printNum(num);
        }
    }
}

void printNum(int num) {
    printf("%d\t", num);
}


void PrintMatrixClockwisely(int **nums, int rows, int cols) {
    if (nums == nullptr || rows <= 0 || cols <= 0) {
        return;
    }
    int start = 0;
    while (cols > start * 2 && rows > start * 2) {
        PrintMatrixInCircle(nums, rows, cols, start);
        ++start;
    }
}