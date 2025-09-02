#include "..\head.h"

// 单调栈
// 先进先出，记录的数据加在最上面，去掉数据爷从最上面开始
// 记录t[i]前会把所有<=t[i]的数据丢掉，不可能出现上大下小

// 及时去掉无用数据，保证栈中数据有序

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--)
        {
            int t = temperatures[i];
            while (!stk.empty() && t >= temperatures[stk.top()])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                ans[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return ans;
    }

    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> stk;

        for (int i = 0; i < n; i++)
        {
            int t = temperatures[i];
            while (!stk.empty() && t > temperatures[stk.top()])
            {
                int j = stk.top();
                stk.pop();
                ans[j] = i - j;
            }
            stk.push(i);
        }
        return ans;
    }
};