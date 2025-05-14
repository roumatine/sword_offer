#include "..\head.h"

Listnode *oddEvenList(Listnode *head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    Listnode *first = head; // 奇数链表头
    Listnode *second = head->next; // 偶数链表头
    Listnode *cur = second; //  保存偶链表头结点

    while (second != nullptr && second->next != nullptr) {
        first->next = second->next;
        second->next = second->next->next;
        first = first->next;
        second = second->next;
    }
    first->next = cur;
    return head;
}

Listnode *oddEvenList2(Listnode *head) {
    if (head == nullptr)
        return head;
    Listnode *p = head;
    Listnode *q = head->next;
    Listnode *evenhead = q;

    while (q != nullptr && q->next != nullptr) {
        p->next = q->next;
        p = p->next;
        q->next = p->next->next;
        q = q->next;
    }
    p->next = evenhead;
    return head;
    
}