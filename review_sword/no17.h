#include "..\head.h"

bool HasSubtreeCore(treeNode *proot1, treeNode *proot2) {
    if (proot2 == nullptr) 
        return true;
    if (proot1 == nullptr) 
        return false;
    if (proot1->val == proot2->val) {
        return HasSubtreeCore(proot1->left, proot2->left) && HasSubtreeCore(proot1->right, proot2->right);
    } else {
        return false;
    }
}

bool HasSubTree(treeNode *proot1, treeNode *proot2) {
    if (proot1 == nullptr || proot2 == nullptr) {
        return false;
    }
    return HasSubTree(proot1->left, proot2) || HasSubTree(proot1->right, proot2) || HasSubtreeCore(proot1, proot2); // 左子树或右子树或根节点
}