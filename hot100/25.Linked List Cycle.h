#include "..\head.h"

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                while (slow != head)
                {
                    slow = slow->next;
                    head = head->next;
                }
                return slow;
            }
        }
    }
};