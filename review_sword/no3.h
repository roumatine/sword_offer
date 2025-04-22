/*
No.3 从尾到头打印链表

输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。

*/

#include "..\head.h"

vector<int> printListFromTailToHead(ListNode* head) {
    if (head == nullptr) {
        return vector<int>();
    }
    vector<int> res;

    while (head != nullptr) {
        res.push_back(head->m_nValue);
        head = head->m_pNext;
    }
    reverse(res.begin(), res.end());
    return res;
}

// 不适用reverse

vector<int> printListFromTailToHead_i(ListNode* head) {
    if (head == nullptr) {
        return vector<int>();
    }
    vector<int> res;
    while (head != nullptr) {
        res.push_back(head->m_nValue);
        head = head->m_pNext;
    }
    // reverse(res.begin(), res.end());
    return vector<int>(res.rbegin(), res.rend()); // 逆序迭代器
}