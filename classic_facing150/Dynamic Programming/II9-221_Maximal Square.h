#include "..\..\head.h"

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix[0].size();
        vector<int> height(n + 1);
        int ans = 0;
        for (auto &row : matrix)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[j] == '0')
                {
                    height[j] = 0;
                }
                else
                {
                    height[j]++;
                }
            }
            ans = max(ans, laegestSize(height));
        }
        return ans * ans;
    }

private:
    int laegestSize(vector<int> &heights)
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
                ans = max(ans, min(heights[i], right - left - 1));
            }
            stk.push(right);
        }
        return ans;
    }
};