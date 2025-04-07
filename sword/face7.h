#include "head.h"

using namespace std;

template <typename T> class CQue {
public:
    CQue(void);
    ~CQue(void);

    void appendTail(const T& node);

    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> CQue<T>::CQue(void) {}
template <typename T> CQue<T>::~CQue(void) {}
template <typename T> void CQue<T>::appendTail(const T& element) {
    stack1.push(element);
}

template<typename T> T CQue<T>::deleteHead() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            T& data = stack1.top();
            stack1.top();
            stack1.push(data);
        }
    }
    if (stack2.size() == 0) {
        return -1;
    }
    T head = stack2.top();
    stack2.pop();
    return head;
}