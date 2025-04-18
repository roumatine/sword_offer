#include "..\head.h"

int knap_sack_dfs(vector<int> &wgt, vector<int> &val, int i, int c) {
    if (i == 0 || c == 0) {
        return 0;
    }
    if (wgt[i - 1] > c) {
        return knap_sack_dfs(wgt, val, i - 1, c);
    }
    int no = knap_sack_dfs(wgt, val, i - 1, c);
    int yes = knap_sack_dfs(wgt, val, i - 1, c - wgt[i - 1]) + val[i - 1];
    return max(no, yes);
}

int knap_sack_dfs_mem(vector<int> &wgt, vector<int> &val, vector<vector<int>> &mem, int i, int c) {
    if (i == 0 || c == 0) {
        return 0;
    }
    if (mem[i][c] != -1) {
        return mem[i][c];
    }
    int no = knap_sack_dfs_mem(wgt, val, mem, i - 1, c);
    int yes = knap_sack_dfs_mem(wgt, val, mem, i - 1, c - wgt[i - 1]) + val[i - 1];
    if (wgt[i - 1] > c) {
        return no;
    }
    mem[i][c] = max(no, yes);
    return mem[i][c]; 
}

int knap_sack_dp(vector<int> &wgt, vector<int> &val, int cap) {
    int n = wgt.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= cap; c++) {
            if (wgt[i - 1] > c) {
                dp[i][c] = dp[i - 1][c];
            } else {
                dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][cap];
}

int knap_sack_cmp(vector<int> &wgt, vector<int> &val, int cap) {
    int n = wgt.size();
    vector<int> dp(cap + 1, 0);
    for (int i = 1; i <= n; i ++) {
        for (int c = cap; c >= 1; c --) {
            if (wgt[i - 1] <= c) {
                dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[cap];
}