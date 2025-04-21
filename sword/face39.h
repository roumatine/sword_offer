#include "..\head.h"
#include "face39_ii.h"

int TreeDepth(BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return 0;
    }

    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);
    return (left > right) ? (left + 1) : (right + 1);
}

int is_balanced(BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) {
        return true;
    }
    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);
    int diff = left - right;
    if (diff > 1 || diff < -1) {
        return false;
    }
    return is_balanced(pRoot->m_pLeft) && is_balanced(pRoot->m_pRight);
}

is_balanced_ii(BinaryTreeNode* pRoot) {
    int depth = 0;
    return is_balanced(pRoot, &depth);
}