#include "..\head.h"

struct ListNode {
    int val;
    struct  ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}  
};
Listnode *MergeCore(Listnode *pHead1, ListNode *pHead2) {
    if (pHead1 == nullptr) {
        return pHead2;
    }
    if (pHead2 == nullptr) {
        return pHead1;
    }

    if (pHead1->val <= pHead2->val) {
        pHead1->next = MergeCore(pHead1->next, pHead2);
        return pHead1;
    } else {
        pHead2->next = MergeCore(pHead1, pHead2->next);
        return pHead2;
    }
}

void Mergecore(ListNode *newHead, ListNode *node1, ListNode *node2) {
    if (node1 == nullptr || node2 == nullptr) {
        newHead->next = (node1 ? node1 : node2);
        return;
    }
    if (node1->val < node2->val) {
        newHead->next = node1;
        node1 = node1->next;
    } else {
        newHead->next = node2;
        node2 = node2->next;
    }
    newHead = newHead->next;
    Mergecore(newHead, node1, node2);
}