#include "..\head.h"

class Solution
{
public:
    ListNode *left;
    ListNode *right;
    bool res = true;
    void traverse(ListNode *right)
    {
        if (right == nullptr)
        {
            return;
        }

        traverse(right->next);

        if (left->val != right->val)
        {
            res = false;
        }
        left = left->next;
    }

    bool isPalindrome(ListNode *head)
    {
        left = head;
        traverse(head);
        return res;
    }
};