#include "..\head.h"

ListNode* findKtotail(ListNode* pListHead, unsigned int k) {
    int count = 0;
    ListNode *node = pListHead;
    while (pListHead != nullptr) {
        count++;
        pListHead = pListHead->m_pNext;
    }
    count = count - k;
    if (count < 0) 
        return nullptr;
    while (count --) {
        node = node->m_pNext;
    }
    return node;
}