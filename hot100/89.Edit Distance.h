#include "..\head.h"

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
    // 递推
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector f(n + 1, vector<int>(m + 1));
        for (int j = 0; j < m; j++)
        {
            f[0][j + 1] = j + 1;
        }
        for (int i = 0; i < n; i++)
        {
            f[i + 1][0] = i + 1;
            for (int j = 0; j < m; j++)
            {
                f[i + 1][j + 1] = word1[i] == word2[j] ? f[i][j] : min({f[i][j + 1], f[i + 1][j], f[i][j]});
            }
        }
        return f[n][m];
    }

    // 滚动数组
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector f(2, vector<int>(m + 1));
        for (int j = 0; j < m; j++)
        {
            f[0][j + 1] = j + 1;
        }

        for (int i = 0; i < n; i++)
        {
            f[(i + 1) % 2][0] = i + 1;
            for (int j = 0; j < m; j++)
            {
                f[(i + 1) % 2][j + 1] = word1[i] == word2[j] ? f[i % 2][j] : min({f[i % 2][j + 1], f[(i + 1) % 2][j], f[i % 2][j]}) + 1;
            }
        }
        return f[n % 2][m];
    }
    // 一个数组
    int minDistance(string word1, string word2)
    {
        int m = word2.size();
        vector<int> f(m + 1);
        for (int j = 0; j < m; j++)
        {
            f[j + 1] = j + 1;
        }
        for (char x : word1)
        {
            int pre = f[0];
            f[0]++;
            for (int j = 0; j < m; j++)
            {
                int tmp = f[j + 1];
                f[j + 1] = x == word2[j] ? pre : min({f[j + 1], f[j], pre}) + 1;
                pre = tmp;
            }
        }
        return f[m];
    }
};