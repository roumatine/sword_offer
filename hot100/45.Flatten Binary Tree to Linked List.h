#include "..\head.h"

class Solution
{
    TreeNode *head;

public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = head;
        head = root;
    }

    TreeNode *dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode *left_tail = dfs(root->left);
        TreeNode *right_tail = dfs(root->right);
        if (left_tail)
        {
            left_tail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        return right_tail ? right_tail : left_tail ? left_tail
                                                   : root;
    }
    void flatten(TreeNode *root)
    {
        dfs(root);
    }
};