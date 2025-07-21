#include "..\..\head.h"

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            auto &p = points[i];
            unordered_map<double, int> unmp;
            for (int j = i + 1; j < n; ++j)
            {
                auto &q = points[j];
                int dx = q[0] - p[0];
                int dy = q[1] - p[1];
                double k = dx ? 1.0 * dy / dx : numeric_limits<double>::infinity();
                ans = max(ans, ++unmp[k]);
            }
        }
        return ans + 1;
    }

    int maxPoints1(vector<vector<int>> &points)
    {
        int n = points.size(), ans = 1;
        for (int i = 0; i < n; i++)
        {
            vector<int> x = points[i];
            for (int j = i + 1; j < n; j++)
            {
                vector<int> y = points[j];
                // 枚举点对 (i,j) 并统计有多少点在该线上, 起始 cnt = 2 代表只有 i 和 j 两个点在此线上
                int cnt = 2;
                for (int k = j + 1; k < n; k++)
                {
                    vector<int> p = points[k];
                    int s1 = (y[1] - x[1]) * (p[0] - y[0]);
                    int s2 = (p[1] - y[1]) * (y[0] - x[0]);
                    if (s1 == s2)
                        cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};