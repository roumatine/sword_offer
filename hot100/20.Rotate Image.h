#include "..\head.h"

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j) // 遍历对角线下方元素
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (auto &row : matrix)
        {
            ranges::reverse(row);
        }
    }
};