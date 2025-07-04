#include "..\..\head.h"

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(0, head);
        auto cur = &dummy;
        while (cur->next && cur->next->next)
        {
            int val = cur->next->val;
            if (cur->next->next->val == val)
            { // 后两个节点值相同
                // 值等于val的节点全部删除
                while (cur->next && cur->next->val == val)
                {
                    auto nxt = cur->next;
                    cur->next = nxt->next;
                    delete nxt;
                    // 内存回收 cur->next = cur->next->next;
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};