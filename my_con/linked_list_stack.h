#include "..\head.h"

class LinkedListStack {
private:
    ListNode* stkTop;
    int stkSize;
public:
    LinkedListStack() {
        stkTop = nullptr;
        stkSize = 0;
    }
    ~LinkedListStack() {
        freeMemoryLinkedList(stkTop);
    }

    int size() {
        return stkSize;
    }
    bool isEmpty() {
        return size() == 0;
    }

    void push(int num) {
        ListNode *node = new ListNode(num);
        node->next = stkTop;
        stkTop = node;
        stkSize++;
    }

    /* 出栈 */
    int pop() {
        int num = top();
        ListNode *tmp = stkTop;
        stkTop = stkTop->next;
        // 释放内存
        delete tmp;
        stkSize--;
        return num;
    }

    /* 访问栈顶元素 */
    int top() {
        if (isEmpty())
            throw out_of_range("栈为空");
        return stkTop->value;
    }

    /* 将 List 转化为 Array 并返回 */
    vector<int> toVector() {
        ListNode *node = stkTop;
        vector<int> res(size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};