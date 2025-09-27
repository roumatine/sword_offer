#include "..\..\head.h"

class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        return root->val == root->left->val + root->right->val;
    }
};

// 扩展： 设二叉树上有 n 个节点（n≥3），且每个节点都有 0 或 2 个儿子。
//      要求判断除了叶子节点，是否每个节点的值都等于其左右儿子的节点值之和。

class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        return root->val == root->left->val + root->right->val && checkTree(root->left) + checkTree(root->right);
    }
};

// 扩展2
// Same Tree
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
        {
            return p == q;
        }
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(q->right, q->right);
    }
};
// Symmetic Tree
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return isSameTree(root->left, root->right);
    }

private:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
        {
            return p == q;
        }
        return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }
};

// Balanced Binary Tree -- 左右子树高度差不超过1，且最大深度为左右子树最大值+ 1
class Solution
{
    int get_height(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left_h = get_height(node->left);
        if (left_h == -1)
        {
            return -1;
        }
        int right_h = get_height(node->right);
        if (right_h == -1 || abs(left_h - right_h) > 1)
        {
            return -1;
        }
        return max(left_h, right_h) + 1;
    }

public:
    // int x = 0;
    bool isBalanced(TreeNode *root)
    {
        // int y = get_height(root);
        // return x > 1 ? false : true;
        return get_height(root) != -1;
    }
};