#include "..\head.h"

int edit_distance_dp(string s, string t) {
    int n = s.size();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i ++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j ++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[n][m];
}

int edit_distance_dp_cmp(string s, string t) {
    int n = s.length();
    int m = t.length();

    vector<int> dp(m + 1, 0);
    for (int j = 1; j <= m; j ++) {
        dp[j] = j;
    }
    for (int i = 1; i <= n; i ++) {
        int leftup = dp[0];
        dp[0] = i;
        for (int j = 1; j <= m; j ++) {
            int tmp = dp[j];
            if (s[i - 1] == t[j - 1]) {
                dp[j] = leftup;
            } else {
                dp[j] = min(min(dp[j - 1], dp[j]), leftup) + 1;
            }
            leftup = tmp;
        }
    }
    return dp[m];
}