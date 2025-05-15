#include "..\..\head.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    return preorderTraversalCore(res, root);
}

vector<int> preorderTraversalCore(vector<int> &res, TreeNode *root) { 
    if (root != nullptr)
        res.push_back(root->val);
    if (root->left != nullptr)
        preorderTraversalCore(res, root->left);
    if (root->right != nullptr)
        preorderTraversalCore(res, root->right);
    return res;
}


// 模板写法
vector<int> preorderTraversal(TreeNode *root) { 
    stack<TreeNode*> stk;
    vector<int> res;
    while (root != nullptr || !stk.empty()) {
        if (root != nullptr) {
            res.push_back(root->val);
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
            root = root->right;

        }
    }
    return res;
}