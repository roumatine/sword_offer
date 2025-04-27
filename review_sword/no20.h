#include "..\head.h"

class Solution {
    int minNum = INT_MAX;
    stack<int> st;
public :
    void push(int val) {
        minNum = std::min(val, minNum);
        st.push(minNum);
        st.push(val);
    }
    void pop() {
        st.pop();
        st.pop();
        if (!st.empty()) {
            int tmp = st.top();
            st.pop();
            minNum = st.top();
            st.push(tmp);
        }
    }
    int top() {
        return st.top();
    }
    int min() {
        return minNum;
    }
};