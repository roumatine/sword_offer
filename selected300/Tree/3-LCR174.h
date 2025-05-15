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
public:
    int findTargetNode(TreeNode* root, int cnt) {
        this->cnt = cnt;
        dfs(root);
        return res;
    }
private:
    int res = 0;
    int cnt = 0;
    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        dfs(root->right);
        if (cnt == 0) return;
        if (--cnt == 0) res = root->val;
        dfs(root->left);
    }
};