#include "..\..\head.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 由于可能会删除链表头部，用哨兵节点简化代码
        ListNode dummy{0, head};
        ListNode *left = &dummy;
        ListNode *right = &dummy;

        while (n--)
        {
            right = right->next; // 右指针先向右走 n 步
        }
        // 左右指针一起走
        while (right->next)
        {
            left = left->next;
            right = right->next;
        }
        // 左指针的下一个节点就是倒数第 n 个节点
        ListNode *neeext = left->next;
        left->next = left->next->next;
        delete neeext;
        return dummy.next;
    }
};