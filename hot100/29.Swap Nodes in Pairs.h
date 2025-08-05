#include "..\head.h"

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(0, head);
        ListNode *node0 = &dummy;
        ListNode *node1 = head;
        while (node1 && node1->next)
        {
            ListNode *node2 = node1->next;
            ListNode *node3 = node2->next;

            node0->next = node2; // 0 -> 2
            node2->next = node1; // 2 -> 1
            node1->next = node3; // 1 -> 3

            node0 = node1; // 下一轮交换，0 是 1
            node1 = node3; // 下一轮交换，1 是 3
        }
        return dummy.next;
    }

    ListNode *swapPairs_recursion(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *node1 = head;
        ListNode *node2 = head->next;
        ListNode *node3 = node2->next;

        node1->next = swapPairs_recursion(node3);
        node2->next = node1;
        return node2;
    }
};