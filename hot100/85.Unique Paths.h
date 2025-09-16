#include "..\head.h"

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector memo(m, vector<int>(n));

        auto dfs = [&](this auto &&dfs, int i, int j) -> int
        {
            if (i < 0 || j < 0)
            {
                return 0;
            }
            if (i == 0 && j == 0)
            {
                return 1;
            }
            int &res = memo[i][j];
            if (res)
            {
                return res;
            }
            return res = dfs(i - 1, j) + dfs(i, j - 1);
        };
        return dfs(m - 1, n - 1);
    }
};