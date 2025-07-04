#include "..\..\head.h"
class Solution
{
    // 迭代
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 创建一个哨兵节点，作为合并后的新链表头节点的前一个节点。
        // 这样可以避免单独处理头节点，也无需特判链表为空的情况，从而简化代码
        ListNode dummy;
        ListNode *cur = &dummy;

        while (list1 && list2)
        {
            // 比较list1和lis2的节点值，如果list1小则把其放到新链表末尾，然后把list1替换成它的下一个节点
            if (list1->val < list2->val)
            {
                cur->next = list1; // 把list1加入到新链表中
                list1 = list1->next;
            }
            else // list2小同理
            // 若一样大小，两者同样，不妨把list2加到新链表末
            {
                cur->next = list2;
                list2 = list2->next;
            }
            // 重复以上过程直到一个链表为空
            cur = cur->next;
        }
        // 循环结束后，其中一个链表可能还有剩余的节点，将剩余部分加到新链表末尾
        cur->next = list1 ? list1 : list2;
        // 最后返回新链表的头节点，即哨兵节点的下一个节点
        return dummy.next;
    }
};

class Solution
{
    // 递归
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 递归边界：如果其中一个链表为空，直接返回另一个链表作为合并后的结果
        // 如果两个链表都不为空，则比较两个链表当前节点的值，并选择较小的节点作为新链表的当前节点
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};