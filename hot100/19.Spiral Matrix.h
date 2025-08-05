#include "..\head.h"

class Solution
{
    static constexpr int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m * n);
        int i = 0, j = 0, di = 0;
        for (int k = 0; k < m * n; ++k)
        {
            ans[k] = matrix[i][j];
            matrix[i][j] = INT_MAX;
            int x = i + DIRS[di][0];
            int y = j + DIRS[di][1];
            if (x < 0 || x >= m || y < 0 || y >= 0 || matrix[x][y] == INT_MAX)
            {
                di = (di + 1) % 4;
            }
            i += DIRS[di][0];
            j += DIRS[di][1];
        }
        return ans;
    }

    vector<int> spiralOrder_nochange(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int size = m * n;
        vector<int> ans;
        int i = 0;
        int j = -1;
        for (int di = 0; ans.size() < size; di = (di + 1) % 4)
        {
            for (int k = 0; i < n; ++k)
            {
                i += DIRS[di][0];
                j += DIRS[di][1];
                ans.push_back(matrix[i][j]);
            }
            m--;
            swap(n, m);
        }
        return ans;
    }
};