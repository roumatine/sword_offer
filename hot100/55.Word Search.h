#include "..\head.h"

class Solution
{
    static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 是一个4x2的静态常量数组，定义了四个可能的移动方向：右、左、下、上。

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        auto dfs = [&](this auto &&dfs, int i, int j, int k) -> bool
        {
            if (board[i][j] != word[k])
            {
                return false;
            }
            if (k + 1 == word.length())
            {
                return true;
            }
            board[i][j] = 0; // 标记访问

            for (auto &&[dx, dy] : DIRS)
            {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n && dfs(x, y, k + 1))
                {
                    return true;
                }
            }

            board[i][j] = word[k];
            return false;
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};