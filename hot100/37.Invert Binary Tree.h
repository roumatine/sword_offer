#include "..\head.h"

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        auto left = invertTree(root->left);   // 翻转左子树
        auto right = invertTree(root->right); // 翻转右子树
        // 交换左右儿子
        root->left = right;
        root->right = left;
        return root;
    }

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