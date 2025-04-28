/*
no.36 两个链表的第一个公共结点
输入两个链表，找出它们的第一个公共结点。
*/

#include "..\head.h"

Listnode* FindFirstCommonNode(Listnode *pHead1, Listnode *pHead2) {
    if (pHead1 == nullptr || pHead2 == nullptr) 
        return nullptr;
    Listnode *p1 = (Listnode*)malloc(sizeof(Listnode));
    Listnode *p2 = (Listnode*)malloc(sizeof(Listnode));
    p1 = pHead1;
    p2 = pHead2;
    while (p1 != p2) {
        p1 = (p1 == nullptr ? pHead2 : p1->next);
        p2 = (p2 == nullptr ? pHead2 : p2->next);
    }
    return p1;
}