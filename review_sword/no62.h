/*
no.62 二叉搜索树的第K个节点
给定一棵二叉树，请找出其中的第K小的结点。
*/
#include "..\head.h"

class situation {
public:
    int cnt = 0;

    treeNode* kthNode(treeNode* pRoot, int k) {
        if (pRoot == nullptr)
            return nullptr;
        treeNode* leftNode = kthNode(pRoot->left, k);
        if (leftNode)
            return leftNode;
        cnt ++;
        if (k == cnt)
            return pRoot;
        treeNode* rightNode = kthNode(pRoot->right, k);
        if (rightNode)
            return rightNode;
        return nullptr;
    }
};

treeNode* kth_node(treeNode *pRoot, int k) {
    if (pRoot == nullptr)
        return nullptr;
    stack<treeNode*> stk;
    stk.push(pRoot);
    while (!stk.empty() || pRoot != nullptr) {
        if (pRoot != nullptr) {
            stk.push(pRoot);
            pRoot = pRoot->left;
        } else {
            pRoot = stk.top();
            stk.pop();
            k --;
            if (k == 0) 
                return pRoot;
            pRoot = pRoot->right;
        }
    }
    return nullptr;
}