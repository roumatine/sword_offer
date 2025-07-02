#include "..\..\head.h"

class MinStack
{

    stack<pair<int, int>> stk;

public:
    MinStack()
    {
        stk.emplace(0, INT_MAX);
    }

    void push(int val)
    {
        stk.emplace(val, min(getMin(), val));
    }

    void pop()
    {
        stk.pop();
    }

    int top()
    {
        return stk.top().first;
    }

    int getMin()
    {
        return stk.top().second;
    }
};
