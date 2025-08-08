#include "..\head.h"

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return isSameTree(root->left, root->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
        {
            return p == q;
        }

        return p->val == p->val && isSameTree(p->left, q->right) && isSameTree(p->right, p->left);
    }
};