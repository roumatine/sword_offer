#include "..\head.h"

void Mirror(treeNode *pRoot) {
    if (pRoot == nullptr) 
        return;
    treeNode *tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    // swap(pRoot->left, pRoot->right);
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}