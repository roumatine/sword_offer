#include "..\head.h"

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // ranges::sort(intervals);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> vec;
        for (auto &p : intervals)
        {
            if (!vec.empty() && p[0] <= vec.back()[1])
            {
                vec.back()[1] = max(vec.back()[1], p[1]);
            }
            else
            {
                vec.emplace_back(p);
            }
        }
        return vec;
    }
};