#include "..\Utilities\List.h"
#include <list>
#include <iostream>
#include <stack>
#include <utility>

void PrintListReversingly_Iterratively(ListNode* pHead) {
    std::stack<Listnode*> nodes;

    ListNode* pNode = pHead;
    while(pNode != nullptr) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!node.empty()) {
        pNode = nodes.top();
        std::cout << pNode->m_nValue << " ";
        nodes.pop();
    }
}

/* 
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != nullptr)
    {
        if (pHead->m_pNext != nullptr)
        {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
 
        printf("%d\t", pHead->m_nValue);
    }
}
*/