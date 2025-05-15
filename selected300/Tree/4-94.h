#include "..\..\head.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 前中后序模板
// while (栈非空||p非空) {
//     if (p非空) {

//     } else {

//     }
// }

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    inorderTraversalCore(res, root);
}

vector<int> inorderTraversalCore(vector<int> &res, TreeNode *root) {
    if (root->left != nullptr)
        inorderTraversalCore(res, root->left);
    res.push_back(root->val);
    if (root->right != nullptr)
        inorderTraversalCore(res, root->right);
    return res;
}

//基于stack
vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> res;
    while (root != nullptr || !s.empty()) {
        if (root != nullptr) {
            s.push(root);
            root = root->left;
        } else {
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
    }
}