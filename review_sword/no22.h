#include "..\head.h"

vector<int> PrintFromTopToBottom(treeNode *root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    queue<treeNode *> q;
    q.push(root);
    treeNode* node;
    while (!q.empty()) {
        node = q.front();
        res.push_back(node->val);
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);

        }
        q.pop();
    }
    return res;
}