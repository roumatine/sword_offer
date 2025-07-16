#include "..\..\head.h"

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return _isValidBst(root, nullptr, nullptr);
    }

    bool _isValidBst(TreeNode *root, TreeNode *min, TreeNode *max)
    {
        if (root == nullptr)
            return true;
        if (min != nullptr && root->val <= min->val)
            return false;
        if (max != nullptr && root->val >= max->val)
            return false;

        return _isValidBst(root->left, min, root) && _isValidBst(root->right, root, max);
    }
};

class Solution
{ // 前序遍历
    long long left = LLONG_MIN;
    long long right = LLONG_MAX;

public:
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        long long x = root->val;
        return left < x && x < right && isValidBST(root->left, left, x) && isValidBST(root->right, x, right);
    }
};

class Solution
{
    long long pre = LLONG_MIN;

public: // 中序遍历
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (!isValidBST(root->left))
        { // 左
            return false;
        }
        if (root->val <= pre)
        { // 中
            return false;
        }
        pre = root->val;
        return isValidBST(root->right); // 右
    }
}

class Solution
{
    long long pre = LLONG_MIN;

private:
    pair<long long, long long> dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {LLONG_MAX, LLONG_MIN};
        }
        auto [l_min, l_max] = dfs(node->left);
        auto [r_min, r_max] = dfs(node->right);
        long long x = node->val;
        if (x <= l_max || x >= r_min)
        {
            return {LLONG_MIN, LLONG_MAX};
        }
        return {min(l_min, x), max(r_max, x)};
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return dfs(root).second != LLONG_MAX;
    }
}