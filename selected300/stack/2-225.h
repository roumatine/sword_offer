#include "..\..\head.h"

class MyStack {
    std::queue<int> q;
    int top_elem = 0;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        top_elem = x;
    }
    
    int pop() {
        int size = q.size();
        while (size > 2) {
            q.push(q.front());
            q.pop();
            size --;
        }
        top_elem = q.front();
        q.push(q.front());
        q.pop();
        int target = q.front();
        q.pop();
        return target;

    }
    
    int top() {
        return top_elem;
    }
    
    bool empty() {
        return q.empty();
    }
};