#include "..\head.h"


int dfs(int i) {
    if (i == 1 || i == 2) {
        return 1;
    }
    int count = dfs(i - 1) + dfs(i - 2);
    return count;
}

int climbing_stairs_dfs(int n) {
    return dfs(n);
}