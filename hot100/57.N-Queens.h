#include "..\head.h"

class Solution
{ // 不同行，不同列-> 每行每列都恰好有一个皇后
  // 不同一斜线-> 右上: 行+列之和不变， 左上: 行-列之差不变
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<int> queens(n);
        vector<uint8_t> col(n); // vector<uint8_t> 效率比 vector<bool> 高
        vector<uint8_t> diag1(n * 2 - 1), diag2(n * 2 - 1);

        auto dfs = [&](this auto &&dfs, int r)
        {
            if (r == n)
            {
                vector<string> board(n);
                for (int i = 0; i < n; i++)
                {
                    board[i] = string(queens[i], '.') + 'Q' + string(n - 1 - queens[i], '.');
                }
                ans.push_back(board);
                return;
            }

            for (int c = 0; c < n; c++)
            {
                int rc = r - c + n - 1;
                if (!col[c] && !diag1[r + c] && !diag2[rc])
                // diag1[r + c]：主对角线（左上到右下）
                // diag2[r - c + n - 1]：副对角线（右上到左下）
                { // 判断能否放皇后
                    queens[r] = c;
                    col[c] = diag1[r + c] = diag2[rc] = true; // 皇后占用了 c 列和两条斜线
                    dfs(r + 1);
                    col[c] = diag1[r + c] = diag2[rc] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }

    vector<vector<string>> solveNQueens_1(int n)
    {
        vector<vector<string>> ans;
        vector board(n, string(n, '.'));
        vector<uint8_t> col(n), diag1(2 * n - 1), diag2(n * 2 - 1);
        auto dfs = [&](this auto &&dfs, int r)
        {
            if (r == n)
            {
                ans.emplace_back(board);
                return;
            }

            for (int c = 0; c < n; c++)
            {
                int rc = r - c + n - 1;
                if (!col[c] && !diag1[r + c] && !diag2[rc])
                {
                    board[r][c] = 'Q';
                    col[c] = diag1[r + c] = diag2[rc] = true;
                    dfs(r + 1);
                    col[c] = diag1[r + c] = diag2[rc] = false;
                    board[r][c] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
};