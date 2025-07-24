#include "..\..\head.h"

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix[0].size();
        vector<int> heights(n + 1);
        int ans = 0;
        for (auto &row : matrix)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[j] == '0')
                {
                    heights[j] = 0;
                }
                else
                {
                    heights[j]++;
                }
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }

private:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int right = 0; right < heights.size(); right++)
        {
            while (stk.size() > 1 && heights[right] <= heights[stk.top()])
            {
                int i = stk.top();
                stk.pop();
                int left = stk.top();
                ans = max(ans, heights[i] * (right - left - 1));
            }
            stk.push(right);
        }
        return ans;
    }
};