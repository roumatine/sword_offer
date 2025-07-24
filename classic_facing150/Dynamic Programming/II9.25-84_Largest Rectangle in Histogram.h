#include "..\..\head.h"

class Solution
{
public:
    int largestRectangleArea_3(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n, -1);
        stack<int> stk;

        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[i] <= heights[stk.top()])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        vector<int> right(n, n);
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && heights[i] <= heights[stk.top()])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }

    int largestRectangleArea_2(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n - 1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[i] <= heights[stk.top()])
            {
                right[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty())
            {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(-1);
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