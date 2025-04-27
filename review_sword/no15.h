#include "..\head.h"

struct ListNode {
    int val;
    struct  ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}  
};

ListNode *ReverseList(ListNode *phead) {
    struct ListNode *head = nullptr;
    struct ListNode *node = (ListNode*)malloc(sizeof(ListNode));

    while (phead != nullptr) {
        node = phead;
        phead = phead->next;
        node->next = head;
        head = node;
    }
    return head;
}

ListNode* Reverse(ListNode* pHead) {
    if (pHead == nullptr || pHead->next == nullptr) {
        return pHead;
    }
    ListNode* pre = nullptr;
    ListNode* cur = pHead;
    ListNode* after = pHead->next;

    while (cur != nullptr) {
        cur->next = pre;
        pre = cur;
        cur = after;
        if (after != nullptr) {
            after = after->next;
        }
    }
    return pre;
}