#include "..\..\head.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int depth = 0;
    int res = 0;
public:
    void traverse(TreeNode* root) {
        if (root == nullptr)
            return;

        depth++;
        if (root->left == nullptr && root->right == nullptr) {
            res = std::max(res,depth);
        }
        traverse(root->left);
        traverse(root->right);
        depth--;
    }
    int maxDepth(TreeNode* root) {
        traverse(root);
        return res;
    }
};