#include "..\head.h"

bool isEqual(treeNode* node1, treeNode* node2) {
    if (node1 == nullptr && node2 == nullptr)   
        return true;
    if (node1 == nullptr || node2 == nullptr) {
        return false;
    }
    if (node1->val == node2->val) {
        return isEqual(node1->left, node2->left) &&
            isEqual(node1->right, node2->right);
    } else {
        return false;
    }
}
bool isSymmetrical(treeNode* pRoot) {
    if (pRoot == nullptr)
        return true;
    return isEqual(pRoot->left, pRoot->right);
}