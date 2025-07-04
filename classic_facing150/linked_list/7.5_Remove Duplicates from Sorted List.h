#include "..\..\head.h"

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *cur = head;
        while (cur->next)
        {
            if (cur->next->val == cur->val)
            {
                ListNode *nxt = cur->next;
                cur->next = nxt->next;
                delete nxt;
                // cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr)
        {
            if (fast->val != slow->val)
            {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};