#include "..\head.h"
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n, -1);
        stack<int> stk;

        for (int i = 0; i < n; i++)
        {
            int h = heights[i];
            while (!stk.empty() && heights[stk.top()] >= h)
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

        for (int i = n - 1; i >= 0; i++)
        {
            int h = heights[i];
            while (!stk.empty() && heights[stk.top()] >= h)
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                right[i] = stk.top();
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
            int h = heights[i];
            while (!stk.empty() && heights[stk.top()] >= h)
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

    int largestRectangleArea_1(vector<int> &heights)
    {
        heights.push_back(-1);
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int right = 0; right < heights.size(); right++)
        {
            int h = heights[right];
            while (stk.size() > 1 && heights[stk.top()] >= h)
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

    int largestRectangleArea__1(vector<int> &heights)
    {
        vector<int> vec;
        vec.push_back(0);
        vec.insert(vec.end(), heights.begin(), heights.end());
        vec.push_back(0);

        int n = vec.size();
        int ans = 0;
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && vec[i] < vec[stk.top()])
            {
                int h = vec[stk.top()];
                stk.pop();
                int w = i - stk.top() - 1;
                ans = max(ans, h * w);
            }
            stk.push(i);
        }
        return ans;
    }
};