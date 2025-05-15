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
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        kthSmallestCore(root, k, ans);
        return ans;
    }
    void kthSmallestCore(TreeNode *root, int &k, int &ans) {
        if (root == nullptr) return;
        if (root->left) kthSmallestCore(root->left, k, ans);
        k --;
        if (k == 0) {
            ans = root->val;
        }
        if (root->right) kthSmallestCore(root->right, k, ans);
    }
};