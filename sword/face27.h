#include "face18.h"

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList) {
    if (pNode == nullptr) {
        return;
    }

    BinaryTreeNode* pCurr = pNode; // 当前节点
    if (pCurr->m_pleft != nullptr) {
        ConvertNode(pCurr->m_pleft, pLastNodeInList); // 递归处理左子树
    }

    pCurr->m_pleft = *pLastNodeInList; // 将当前节点的左指针指向当前链表的尾节点
    if (*pLastNodeInList != nullptr) {
        (*pLastNodeInList)->m_pright = pCurr; // 将当前链表的尾节点的右指针指向当前节点
    }

    *pLastNodeInList = pCurr; // 将当前节点设置为当前链表的尾节点
    if (pCurr->m_pright != nullptr) {
        ConvertNode(pCurr->m_pright, pLastNodeInList); // 递归处理右子树
    }
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree) {
    BinaryTreeNode* pLastNodeInList = nullptr;
    ConvertNode(pRootOfTree, &pLastNodeInList);
    BinaryTreeNode* pHeadOfList = pLastNodeInList;
    while (pHeadOfList != nullptr && pHeadOfList->m_pleft != nullptr) { // 找到链表的头节点
        pHeadOfList = pHeadOfList->m_pleft; // 循环找到链表的头节点
    }
    return pHeadOfList;
}

void DestroyList(BinaryTreeNode *pHeadOfList) {
    BinaryTreeNode *pNode = pHeadOfList;
    while (pNode != nullptr) {
        BinaryTreeNode *pNext = pNode->m_pright;
        delete pNode;
        pNode = pNext;
    }
}

void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList) {
    BinaryTreeNode* pNode = pHeadOfList;
    printf("The nodes from left to right are:\n");
    while(pNode != nullptr) {
        printf("%d\t", pNode->m_value);

        if (pNode->m_pright == nullptr) {
            break;
        }
        pNode = pNode->m_pright;
    }

    printf("\nThe nodes from right to left are:\n");
    while(pNode != nullptr) {
        printf("%d\t", pNode->m_value);
        if (pNode->m_pleft == nullptr) {
            break;
        }
        pNode = pNode->m_pleft; // 循环找到链表的尾节点
    }
    printf("\n");
}