#include "..\..\head.h"

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    { // 最小堆
        auto cmp = [](const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq;
        for (auto head : lists)
        {
            if (head)
            {
                pq.push(head);
            }
        }

        ListNode dummy{};
        auto cur = &dummy;
        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            if (node->next)
            {
                pq.push(node->next);
            }
            cur->next = node;
            cur = cur->next;
        }
        return dummy.next;
    }
}

class Solution

{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return mergeKLists(list, 0, lists.size());
    }

private:
    ListNode *MergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy{};
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
        return dummy->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists, int i, int j)
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
        auto left = mergeKLists(lists, i, i + m / 2);
        auto right = mergeKLists(lists, i + m / 2, j);
        return MergeTwoLists(left, right);
    }
};

class Solution
{
private:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
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

public:
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
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
            }
        }
        return list[0];
    }
};