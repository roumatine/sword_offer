#include "..\head.h"

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p = headA;
        ListNode *q = headB;
        while (p != q)
        {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }

    ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != p2)
        {
            if (p1 == nullptr)
            {
                p1 = headB;
            }
            else
            {
                p1 = p1->next;
            }
            if (p2 == nullptr)
            {
                p2 = headA;
            }
            else
            {
                p2 = p2->next;
            }
        }
        return p1;
    }
};