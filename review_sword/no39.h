/*
no.39 判断是不是平衡二叉树
输入一颗二叉树，判断该二叉树是否是平衡二叉树。
考虑平衡性，不需要考虑是否是排序二叉树
*/

#include "..\head.h"

int MaxDepth(treeNode *node) {
    if (node == nullptr)
        return 0;

    return 1 + max(MaxDepth(node->left), MaxDepth(node->right));
}

bool IsBalanced_Solution(treeNode *pRoot) {
    if (pRoot == nullptr)
        return true;
    
    return abs(MaxDepth(pRoot->left) - MaxDepth(pRoot->right)) <= 1 &&
        IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}