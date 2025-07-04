#include "..\..\head.h"

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry = 0)
    {
        int carry = 0;
        if (l1 == nullptr && l2 == nullptr && carry == 0)
        {
            return nullptr;
        }
        int s = carry;
        if (l1)
        {
            s += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            s += l2->val;
            l2 = l2->next;
        }
        return new ListNode(s % 10, addTwoNumbers(l1, l2, s / 10));
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy;         // 作为结果链表的哑节点（哨兵节点），简化边界条件处理
        ListNode *cur = &dummy; // 指针用于构建结果链表
        int carry = 0;          // 记录进位值，初始为0
        while (l1 || l2 || carry)
        {
            // 将当前节点的值加到carry中（如果存在），并移动指针到下一个节点
            if (l1)
            {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                carry += l2->val;
                l2 = l2->next;
            }
            // carry % 10得到当前位的值
            // new ListNode()创建新节点并连接到结果链表
            cur = cur->next = new ListNode(carry % 10);
            carry /= 10; // 计算新的进位值
        }
        return dummy.next;
    }
};