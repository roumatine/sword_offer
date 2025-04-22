
/*
No.4 重建二叉树
给定节点数为 n 的二叉树的前序遍历和中序遍历结果，请重建出该二叉树并返回它的头结点。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树
*/
#include "..\head.h"

TreeNode* reConstructBinaryTree(unordered_map<int, int> &hashMap, vector<int> &pre,
                                int low1, vector<int> &vin, int low2, int high2) {
    if (low1 > (int)pre.size() || low2 > high2) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(pre[low1]);
    
}