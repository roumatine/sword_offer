#include "..\head.h"

void backtrack(vector<int> &choices, int state, int n, vector<int> &res) {
    if (state == n) {
        res[0] ++;
    }
    for (auto &choice: choices) {
        if (state + choice > n) {
            continue;
        }
        backtrack(choices, state + choice, n, res);
    }
}
int climbing_stairs_backtrack(int n) {
    vector<int> choices = {1, 2};
    int state = 0;
    vector<int> res = {0};
    backtrack(choices, state, n, res);
    return res[0];
}
