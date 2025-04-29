/*
no.55 链表中环的入口结点
给一个链表，其中包含环，找到该链表中环的入口结点否则输出null
*/

#include "..\head.h"

Listnode *entry_node_of_loop(Listnode* head) {
    if (head == nullptr)
        return nullptr;
    unordered_map<Listnode*, int> unmp;
    while (head != nullptr) {
        unmp[head] ++;
        if (unmp[head] == 2) 
            return head;
        head = head->next;
    }
    return nullptr;
}

Listnode *EntryNodeOfLoop(Listnode* phead) {
    if (phead == nullptr || phead->next == nullptr)
        return nullptr;
    Listnode *fast = phead, *slow = phead;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }

    if (fast == nullptr || fast->next == nullptr)
        return nullptr;
    slow = phead;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}