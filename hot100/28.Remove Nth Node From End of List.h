#include "..\head.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy{0, head};
        ListNode *left = &dummy;
        ListNode *right = &dummy;

        while (n--)
        {
            right = right->next;
        }
        while (right->next)
        {
            left = left->next;
            right = right->next;
        }
        ListNode *nxt = left->next;
        left->next = left->next->next;
        delete nxt;
        return dummy.next;
    }
};