#include "..\head.h"

class Solution
{
public:
    ListNode *left;
    ListNode *right;
    bool res = true;
    void traverse(ListNode *right)
    {
        if (right == nullptr)
        {
            return;
        }

        traverse(right->next);

        if (left->val != right->val)
        {
            res = false;
        }
        left = left->next;
    }

    bool isPalindrome(ListNode *head)
    {
        left = head;
        traverse(head);
        return res;
    }
};

class Solution1
{
public:
    bool isPalidrome(ListNode *head)
    {
        ListNode *mid = middleNode(head);
        ListNode *head2 = reverseList(mid);
        while (head2)
        {
            if (head->val != head2->val)
            {
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }

private:
    // 链表中间节点
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

class Solution2
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;

        vector<ListNode *> vec;
        ListNode *node = head;
        while (node != nullptr)
        {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0;
        int j = vec.size() - 1;
        while (i < j)
        {
            vec[i]->next = vec[j];
            ++i;
            if (i == j)
            {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};