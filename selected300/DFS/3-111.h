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
private:
    int minDepthValue = INT_MAX;
    int currentDepth = 0;

public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        traverse(root);
        return minDepthValue;
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        currentDepth++;

        if (root->left == nullptr && root->right == nullptr) {
            minDepthValue = min(minDepthValue, currentDepth);
        }
        traverse(root->left);
        traverse(root->right);

        currentDepth--;
    }
};