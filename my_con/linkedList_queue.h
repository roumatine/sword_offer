
#include "head.h"

class LinkedListQueue {
private:
    ListNode* front, *rear;
    int size;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }
    ~LinkedListQueue() {
        freeMemoryLinkedList();
    }

    /* 获取队列的长度 */
    int size() {
        return size;
    }

    /* 判断队列是否为空 */
    bool isEmpty() {
        return size == 0;
    }

    /* 入队 */
    void push(int num) {
        // 在尾节点后添加 num
        ListNode *node = new ListNode(num);
        // 如果队列为空，则令头、尾节点都指向该节点
        if (front == nullptr) {
            front = node;
            rear = node;
        }
        // 如果队列不为空，则将该节点添加到尾节点后
        else {
            rear->next = node;
            rear = node;
        }
        size++;
    }

    /* 出队 */
    int pop() {
        int num = peek();
        // 删除头节点
        ListNode *tmp = front;
        front = front->next;
        // 释放内存
        delete tmp;
        size--;
        return num;
    }

    /* 访问队首元素 */
    int peek() {
        if (size() == 0)
            throw out_of_range("队列为空");
        return front->val;
    }

    /* 将链表转化为 Vector 并返回 */
    vector<int> toVector() {
        ListNode *node = front;
        vector<int> res(size());
        for (int i = 0; i < res.size(); i++) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};