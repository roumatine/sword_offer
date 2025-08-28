#include "..\head.h"

class MinStack
{

    stack<pair<int, int>> stk;

public:
    MinStack() // 初始化堆栈对象
    {
        stk.emplace(0, INT_MAX);
    }

    void push(int val) // 将元素val推入堆栈
    {
        stk.emplace(val, min(getMin(), val));
    }

    void pop() // 删除堆栈顶部的元素
    {
        stk.pop();
    }

    int top() // 删除堆栈顶部的元素
    {
        return stk.top().first;
    }

    int getMin() // 删除堆栈顶部的元素
    {
        return stk.top().second;
    }
};