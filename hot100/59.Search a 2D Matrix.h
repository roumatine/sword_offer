#include "..\head.h"

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = -1;
        int right = m * n;
        while (left + 1 < right)
        {
            int mid = left + (left + right) >> 1;
            int x = matrix[mid / n][mid % n];
            if (x == target)
            {
                return true;
            }
            if (x < target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return false;
    }
};