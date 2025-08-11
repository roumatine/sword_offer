#include "..\head.h"

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        auto dfs = [&](this auto &&dfs, TreeNode *root, long long left = LLONG_MIN, long long right = LLONG_MAX) -> bool
        {
            if (root == nullptr)
            {
                return true;
            }
            long long x = root->val;
            return left < x && x < right &&
                   dfs(root->left, left, x) &&
                   dfs(root->right, x, right);
        };
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }

    long long pre = LLONG_MIN;
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (isValidBST(root->left))
        {
            return false;
        }
        if (root->val <= pre)
        {
            return false; // 节点值小于上个节点
        }
        pre = root->val;
        return isValidBST(root->right);
    }
};