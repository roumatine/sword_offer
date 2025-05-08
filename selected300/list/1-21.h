#include "..\..\head.h"

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) 
        return l2;
    if (l2 == nullptr) 
        return l2;
    ListNode *res = nullptr;
    
    if (l1->val < l2->val) {
        res = l1;
        l1 = l1->next;
    } else {
        res = l2;
        l2 = l2->next;
    }
    ListNode *head = res;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            res->next = l1;
            l1 = l1->next;
            res = res->next;
        } else {
            res->next = l2;
            l2 = l2->next;
            res = res->next;
        }    
    }
    res->next = l1 == nullptr ? l2 : l1;
    return head;
    
}