#include "..\..\head.h"

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        ranges::sort(points, {}, [](auto &p)
                     { return p[1]; });
        int res = 0;
        long long pre = LLONG_MIN;
        for (auto &p : points)
        {
            if (p[0] > pre)
            {
                res++;
                pre = p[1];
            }
        }
        return res;
    }
};