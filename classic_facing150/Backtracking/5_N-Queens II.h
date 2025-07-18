#include "..\..\head.h"

class Solution
{
public:
    int totalNQueens(int n)
    {
        int ans = 0;
        vector<uint8_t> col(n), diag1(n * 2 - 1), diag2(n * 2 - 1);
        auto dfs = [&](this auto &&dfs, int r)
        {
            if (r == n)
            {
                ans++;
                return;
            }
            for (int c = 0; c < n; ++c)
            {
                int rc = r - c + n - 1;
                if (!col(c) && !diag1[r + c] && !diag2[rc])
                {
                    col[c] = diag1[r + c] = diag2[rc] = true;
                    dfs(r + 1);
                    col[c] = diag1[r + c] = diag2[rc] = true;
                }
            }
        };
        dfs(0);
        return ans;
    }
};