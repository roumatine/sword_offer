#include "..\head.h"
/* 回溯算法：全排列 I */
void back_track(vector<int> &state, const vector<int> &choices,
        vector<bool> &selected, vector<vector<int>> &res) {
    if (state.size() == choices.size()) {
        res.push_back(state);
        return;
    }
    // 遍历所有选择
    unordered_set<int> duplicated;
    for (int i = 0; i < choices.size(); i++) {
        int choice = choices[i];
        // 剪枝：不允许重复选择元素 且 不允许重复选择相等元素
        if (!selected[i] && duplicated.find(choice) == duplicated.end()) {
            // 尝试：做出选择，更新状态
            duplicated.emplace(choice); // 记录选择过的元素值
            selected[i] = true;
            state.push_back(choice);
            // 进行下一轮选择
            back_track(state, choices, selected, res);
            // 回退：撤销选择，恢复到之前的状态
            selected[i] = false;
            state.pop_back();
        }
    }
}

/* 全排列 II */
vector<vector<int>> permutationsII(vector<int> nums) {
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    back_track(state, nums, selected, res);
    return res;
}