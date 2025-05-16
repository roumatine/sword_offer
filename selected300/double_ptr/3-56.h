#include "..\..\head.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) 
            return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { 
            return a[0] < b[0]; 
        });
        vector<vector<int>> ans { intervals[0]};
        int n = intervals.size();
        for (int i = 1; i < n; ++i) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        for (int i = 0; i < n ; ++i) {
            int t = intervals[i][1];
            int j = i + 1;
            while (j < n && intervals[j][0] <= t) {
                t = max(t, intervals[j][1]);
                ++j;
            }
            ans.push_back({intervals[i][0], t});
            i = j;
        }
        return ans;
    }
};