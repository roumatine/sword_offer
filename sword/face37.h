#include "..\head.h"


ListNode *find_first_common_node(ListNode *phead1, ListNode *phead2) {
    unsigned int nlength1 = Get_list_length(phead1);
    unsigned int nlength2 = Get_list_length(phead2);

    int nlength_dif = nlength1 - nlength2;
    ListNode *p_list_head_long = phead1;
    ListNode *p_list_head_short = phead2;
    if (nlength2 > nlength1) {
        p_list_head_long = phead2;
        p_list_head_short = phead1;
        nlength_dif = nlength2 - nlength1;
    }
    // 先在长链表上走几步，再同时在两个链表上遍历
    for (int i = 0; i < nlength_dif; ++i) {
        p_list_head_long = p_list_head_long->m_pNext;
    }
    while ((p_list_head_long != nullptr) && (p_list_head_short != nullptr) && (p_list_head_long != p_list_head_short)) {
        p_list_head_long = p_list_head_long->m_pNext;
        p_list_head_short = p_list_head_short->m_pNext;
    }
    ListNode *find_first_common_node = p_list_head_long;
    return find_first_common_node;
    
}

unsigned int Get_list_length(ListNode *phead) {
    unsigned int length = 0;
    ListNode *pnode = phead;
    while(pnode != nullptr) {
        ++length;
        pnode = pnode->m_pNext;
    }
    return length;
}