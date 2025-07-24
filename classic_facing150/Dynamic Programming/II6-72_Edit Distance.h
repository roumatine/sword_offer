#include "..\..\head.h"

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector memo(n, vector<int>(m, -1));
        auto dfs = [&](this auto &&dfs, int i, int j) -> int
        {
            if (i < 0)
            {
                return j + 1;
            }
            if (j < 0)
            {
                return i + 1;
            }
            int &res = memo[i][j];
            if (res != -1)
            {
                return res;
            }
            if (word1[i] == word2[j])
            {
                return res = dfs(i - 1, j - 1);
            }
            return res = min({dfs(i - 1, j), dfs(i, j - 1), dfs(i - 1, j - 1)}) + 1;
        };
        return dfs(n - 1, m - 1);
    }
};