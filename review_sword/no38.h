/*
no.38 二叉树的深度
输入一颗二叉树，求该树深度。
从根结点道叶结点一次经过的结点性成熟的一条路径，最长路径的长度为树的深度
*/

#include "..\head.h"

int TreeDepth(treeNode* pRoot) {
    if (pRoot == nullptr)
        return 0;
    
    queue<pair<treeNode*, int>> q;
    q.push(make_pair(pRoot, 1));
    int maxDept = 1;
    while (!q.empty()) {
        treeNode* curNode = q.front().first;
        int curDept = q.front().second;
        q.pop();
        if (curNode) {
            maxDept = max(maxDept, curDept);
            q.push({curNode->left, curDept + 1});
            q.push({curNode->right, curDept + 1});
        }
    }
    return maxDept;
}

int treedepth(treeNode* pRoot) {
    if (pRoot == nullptr) 
        return 0;

    int left_depth = treedepth(pRoot->left) + 1;
    int right_depth = treedepth(pRoot->right) + 1;
    return max(left_depth, right_depth);
}