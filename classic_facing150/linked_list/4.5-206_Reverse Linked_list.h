#include "..\..\head.h"

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr; // 始终指向已反转部分链表的头节点
        ListNode *cur = head;    // 当前待反转的节点
        while (cur)
        {
            ListNode *neeext = cur->next; // 临时保存cur->next，防止修改指针后丢失后续节点。
            cur->next = pre;
            pre = cur;
            cur = neeext;
        }
        return pre;
    }
};