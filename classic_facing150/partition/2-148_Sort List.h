#include "..\..\head.h"

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *head2 = middleNode(head);
        // 分治
        head = sortList(head);
        head2 = sortList(head2);
        // 合并
        return mergeTwoLists(head, head2);
    }

private:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *pre = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = null;
        return slow;
    }
    ListNode *mergeTwoLists(ListNode *List1, ListNode *List2)
    {
        ListNode dummy;
        ListNode *cur = &dummy;
        while (List1 && List2)
        {
            if (List1->val < List2->val)
            {
                cur->next = List1;
                List1 = List1->next;
            }
            else
            {
                cur->next = List2;
                List2 = List2->next;
            }
            cur = cur->next;
        }
        cur->next = List1 ? List1 : List2; // 拼接剩余链表
        return dummy.next;
    }
};