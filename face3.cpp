#include <cstdio>
#include <iostream>

bool Find(int *matrix, int rows, int columns, int num) {
    bool found = false;
    if (matrix != nullptr && rows > 0 && columns > 0) {
        int row = 0;
        int column = columns - 1;

        while (row < rows && column >= 0) {
            if (matrix[row * columns + column] == num) {
                found = true;
                break;
            } else if (matrix[row * columns + column] > num) {
                column --;
            } else {
                row ++;
            }
        }
    }
    return found;
}

// ====test=====
void Test(char *testName, int *matrix, int rows, int columns, int num, bool exp) {
    if (testName != nullptr) {
        std::cout << testName << " begins:";
    }
    bool result = Find(matrix, rows, columns, num);
    if (result == exp) {
        std::cout << "Passed." << std::endl;
    } else {
        std::cout << "Failed." << std::endl;
    }
}

void Test1() {
    int matrix[][4] = { { 1, 2, 8, 9 },
                         {2, 4, 9, 12 },
                         {4, 7, 10, 13 },
                         {6, 8, 11, 15 } };
    
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, 
                        {2, 4, 9, 12},
                        {4, 7, 10, 13},
                        {6, 8, 11, 15}};
    Test("Test2", (int*)matrix, 4, 4, 5, false);
}

void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test3", (int*)matrix, 4, 4, 1, true);
}

void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test4", (int*)matrix, 4, 4, 15, true);
}