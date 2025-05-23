#include "..\..\head.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> state;
        int start = 0;
        vector<vector<int>> res;
        backtrack(state, target, candidates, start, res);
        return res;
    }

    void backtrack(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res) {
        if (target == 0)
            res.push_back(state);
            return;
        for (int i = start; i < choices.size(); i++) {
            if (target - choices[i] < 0) break;
            if (i > start && choices[i] == choices[i - 1]) continue;
            state.push_back(choices[i]);
            backtrack(state, target - choices[i], choices, i + 1, res);
            state.pop_back();
        }
    }
};