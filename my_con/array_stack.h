#include "head.h"

class ArrayStack { 
private:
    vector<int> stack;
public:
    int size() {
        return stack.size();
    }   

/* 判断栈是否为空 */    
    bool isEmpty() {
        return stack.size() == 0;
    }

    void push(int num) {
        stack.push_back(num);
    }
    int pop() {
        int num = top();
        stack.pop_back();
        return num;
    }

    int top() {
        if (isEmpty()) {
            throw out_of_range("stack is empty");
        }
        return stack.back();
    }

    vector<int> toVector() {
        return stack;
    }
};