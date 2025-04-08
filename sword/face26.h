#pragma once
#include "..\head.h"

struct ComplexListNode
{
    /* data */
    int nValue;
    ComplexListNode* p_Next;
    ComplexListNode* pSibling;
};

ComplexListNode* CreateNode(int Value) {
    ComplexListNode* pNode = new ComplexListNode();
    pNode->nValue = Value;
    pNode->p_Next = nullptr;
    pNode->pSibling = nullptr;
    return pNode;
}
void BuildNode(ComplexListNode* pNode, ComplexListNode* p_Next, ComplexListNode* pSibling) {
    if (pNode != nullptr) {
        pNode->p_Next = p_Next;
        pNode->pSibling = pSibling;
    }
}
void PrintList(ComplexListNode* pHead) {
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr) {
        printf("The value of this node is: %d.\n", pNode->nValue);
        if (pNode->pSibling != nullptr) {
            printf("The value of its sibling is: %d.\n", pNode->pSibling->nValue);
        } else {
            printf("This node does not have a sibling.\n");
        }
        printf("\n");
        pNode = pNode->p_Next;
    }
}
