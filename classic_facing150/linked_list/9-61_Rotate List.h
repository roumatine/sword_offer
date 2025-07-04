#include "..\..\head.h"

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !k)
        {
            return head;
        }
        int n = 0;
        ListNode *tail;
        for (ListNode *p = head; p; p = p->next)
        {
            tail = p;
            n++;
        }
        k % n;
        ListNode *p = head;
        for (int i = 0; i < n - k - 1; ++i)
        {
            p = p->next;
        }
        tail->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0 || head == nullptr || head->next == nullptr)
        {
            return head;
        }
        int n = 1;
        ListNode *iter = head;
        while (iter->next != nullptr)
        {
            iter = iter->next;
            n++;
        }
        int add = n - k % n;
        if (add == n)
        {
            return head;
        }
        iter->next = head;
        while (add--)
        {
            iter = iter->next;
        }
        ListNode *res = iter->next;
        iter->next = nullptr;
        return res;
    }
};