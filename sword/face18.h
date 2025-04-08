#include "..\head.h"

struct  BinaryTreeNode
{
    /* data */
    double m_value;
    BinaryTreeNode* m_pleft;
    BinaryTreeNode* m_pright;
};


bool Equal(double num1, double num2) {
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001)) {
        return true;
    } else {
        return false;
    }
}

bool DoesTreeHaveTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
    if (pRoot1 == nullptr) {
        return false;
    }
    if (pRoot2 == nullptr) {
        return true;
    }
    
    if (!Equal(pRoot1->m_value, pRoot2->m_value)) {
        return false;
    }
    return DoesTreeHaveTree(pRoot1->m_pleft, pRoot2->m_pleft) &&
        DoesTreeHaveTree(pRoot1->m_pright, pRoot2->m_pright);
}

bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
    bool result = false;

    if (pRoot1 != nullptr && pRoot2 != nullptr) {
        if (Equal(pRoot1->m_value, pRoot2->m_value)) {
            result = DoesTreeHaveTree(pRoot1, pRoot2); // 判断根节点是否相同
        }
        if (!result) {
            result = HasSubTree(pRoot1->m_pleft, pRoot2); // 判断左子树是否相同
        }
        if (!result) {
            result = HasSubTree(pRoot1->m_pright, pRoot2); // 判断右子树是否相同
        }
    }
}

BinaryTreeNode* CreateBinaryTreeNode(double value) {
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_value = value;
    pNode->m_pleft = nullptr;
    pNode->m_pright = nullptr;
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