/*
no.60 把二叉树打印成多行
从上到下按层打印二叉树，同一层结点从左至右输出。
每一层输出一行。
*/

#include "..\head.h"

vector<vector<int>> Print(treeNode* pRoot) {
    vector<vector<int>> res;
    if (pRoot == nullptr)
        return res;
    queue<treeNode*> q;
    q.push(pRoot);
    while (!q.empty()) {
        int len = q.size(); // 利用len保存每层的个数
        vector<int> tmp;
        while (len --) {
            treeNode* node = q.front();
            q.pop();
            tmp.push_back(node->val);
            if (node->left)
                q.push(node->left);
                q.push(node->right);
        }
        res.push_back(tmp);
    }
    return res;
}