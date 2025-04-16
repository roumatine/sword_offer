#include "..\head.h"

int dfs(int i, vector<int> &men) {
    if (i == 1 || i == 2) {
        return i;
    }
    if (men[i] != -1) {
        return men[i];
    }
    int count = dfs(i - 1, men) + dfs(i - 2, men);
    men[i] = count;
    return count;
}

int climbing_stairs_dfs_men(int n) {
    vector<int> men(n + 1, -1);
    return dfs(n, men);
}