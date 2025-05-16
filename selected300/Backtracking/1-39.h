#include "..\..\head.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combinationsSumCore(res, candidates, target, tmp, 0, 0);
        return res;
    }
    void combinationsSumCore(vector<vector<int>> &res, vector<int> &candidates, int target, vector<int> &tmp, int sum, int begin) {
        if (sum == target)
            res.push_back(tmp);
        else {
            for (int i = begin; i < candidates.size(); ++i) {
                if (sum + candidates[i] <= target) {
                    tmp.push_back(candidates[i]);
                    combinationsSumCore(res, candidates, target, tmp, sum + candidates[i], i);
                    tmp.pop_back();
                } else {
                    return;
                }
            }
        }
    }
};