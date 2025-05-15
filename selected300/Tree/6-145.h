#include "..\..\head.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr)
        return res;
    postorderTraversalCore(res, root);
    return res;
}

vector<int> postorderTraversalCore(vector<int> &res, TreeNode *root) {
    if (root->left != nullptr)
        postorderTraversalCore(res, root->left);
    if (root->right != nullptr)
        postorderTraversalCore(res, root->right);
    res.push_back(root->val);
}

// 模板
vector<int> preorderTraversal(TreeNode *root) {
    stack<treeNode *> s;
    vector<int> res;
    while (root != nullptr || !s.empty()) {
        if (root != nullptr) {
            res.push_back(root->val);
            s.push(root);
            root = root->right;
        } else {
            root = s.top();
            s.pop();
            root = root->left;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}