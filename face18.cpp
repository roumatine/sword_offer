#include "face18.h"

BinaryTreeNode* CreateBinaryTreeNode(double value) {
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_value = value;
    pNode->m_pleft = nullptr;
    pNode->right = nullptr;
    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
    if (pParent != nullptr) {
        pParent->m_pleft = pLeft;
        pParent->m_pright = pRight;
    }
}

void DestroyTree(BinaryTreeNode* pRoot) {
    if (pRoot != nullptr) {
        BinaryTreeNode* pLeft = pRoot->m_pleft;
        BinaryTreeNode* pRight = pRoot->m_pright;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

void Test(char* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected) {
    if (HasSubTree(pRoot1, pRoot2) == expected) {
        std::cout << testName << " passed." << std::endl;
    } else {
        std::cout << testName << " failed." << std::endl;
    }
}

void Test1()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    Test("Test1", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}