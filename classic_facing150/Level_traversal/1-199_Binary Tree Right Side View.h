#include "..\..\head.h"

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        auto dfs = [&](this auto &&dfs, TreeNode *node, int depth) -> void
        {
            if (node == nullptr)
            {
                return;
            }
            if (depth == res.size())
            {
                res.push_back(node->val);
            }
            dfs(node->right, depth + 1);
            dfs(node->left, depth + 1);
        };
        dfs(root, 0);
        return res;
    }
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        helper(root, 0, res);
        return res;
    }
    void helper(TreeNode *root, int level, vector<int> &res)
    {
        if (!root)
            return;
        if (res.size() == level)
            res.push_back(root->val);
        helper(root->right, level + 1, res);
        helper(root->left, level + 1, res);
    }
};