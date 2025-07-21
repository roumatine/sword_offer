#include "..\..\head.h"

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    { // 二分
        int m = matrix.size();
        int n = matrix[0].size();
        int left = -1;
        int right = m * n;

        while (left + 1 < right)
        {
            int mid = left + ((right - left) >> 1);
            int x = matrix[mid / n][mid % n];
            if (x == target)
            {
                return true;
            }
            (x < target ? left : right) = mid;
        }
        return false;
    }
};

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    { // 排除法
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            if (matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};