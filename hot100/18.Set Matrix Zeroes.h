#include "..\head.h"

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return;
        }
        vector<vector<int>> newMatrix(matrix);
        const int M = matrix.size(), N = matrix[0].size();
        for (int r = 0; r < M; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                if (newMatrix[r][c] == 0)
                {
                    for (int j = 0; j < N; ++j)
                    {
                        matrix[r][j] = 0;
                    }
                    for (int i = 0; i < M; ++i)
                    {
                        matrix[i][c] = 0;
                    }
                }
            }
        }
    }
};