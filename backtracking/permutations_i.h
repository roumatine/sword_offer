#include "..\head.h"
/* 回溯算法：全排列 I */
void back_track(vector<int> &state, const vector<int> &choices,
        vector<bool> &selected, vector<vector<int>> &res) {
    if (state.size() == choices.size()) {
        res.push_back(state);
        return;
    }
    for (int i = 0; i < choices.size(); i++) {
        int choice = choices[i];
        if (!selected[i]) {
            selected[i] = true;
            state.push_back(choice);
            back_track(state, choices, selected, res);
            selected[i] = false;
            state.pop_back();
        }
    }
}

vector<vector<int>> permutationsI(vector<int> nums) {
    vector<int> state;
    vector<bool> selected(nums.size() ,false);
    vector<vector<int>> res;
    back_track(state, nums, selected, res);
    return res;
}