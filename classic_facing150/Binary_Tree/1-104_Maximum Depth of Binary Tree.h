#include "..\..\head.h"

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }
};

class Solution
{
public:
    void traverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        }
};