#include "..\head.h"

class Solution
{

    ListNode *mergeLists(ListNode *list1, ListNode *list2)
    { // 21. 合并两个有序链表
        ListNode dummy{};
        auto cur = &dummy;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy.next;
    }
    // 合并从 lists[i] 到 lists[j-1] 的链表
    ListNode *mergeK_Lists(vector<ListNode *> &lists, int i, int j)
    {
        int m = j - i;
        if (m == 0)
        {
            return nullptr;
        }
        if (m == 1)
        {
            return lists[i];
        }
        auto left = mergeK_Lists(lists, i, i + m / 2);
        auto right = mergeK_Lists(lists, i + m / 2, j);
        return mergeLists(left, right);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return mergeK_Lists(lists, 0, lists.size());
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int m = lists.size();
        if (m == 0)
        {
            return nullptr;
        }
        for (int step = 1; step < m; step *= 2)
        {
            for (int i = 0; i < m - step; i += step * 2)
            {
                lists[i] = mergeLists(lists[i], lists[i + step]);
            }
        }
        return lists[0];
    }
};