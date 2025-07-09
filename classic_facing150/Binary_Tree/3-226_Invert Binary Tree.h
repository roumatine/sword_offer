#include "..\..\head.h"

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        // TreeNode* left = invertTree(root->left);
        // TreeNode *right = invertTree(root->right);
        auto left = invertTree(root->left);
        auto right = invertTree(root->right);

        root->left = right;
        root->right = left;
        return root;
    }
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};