#include "..\..\head.h"

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode dummy(0, head);
        ListNode *p0 = &dummy;
        for (int i = 0; i < left - 1; ++i)
        {
            p0 = p0->next;
        }

        ListNode *pre = nullptr;
        ListNode *cur = p0->next;
        for (int i = 0; i < right - left + 1; ++i)
        {
            ListNode *neeext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = neeext;
        }

        p0->next->next = cur;
        p0->next = pre;
        return dummy.next;
    }
};