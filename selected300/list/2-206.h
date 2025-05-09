#include "..\..\head"


class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* pre = nullptr;
            ListNode* cur = head;
            ListNode* next = nullptr;
            while (cur) {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        }
    };