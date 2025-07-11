#include "..\..\head.h"

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> path;
        auto dfs = [&](this auto &&dfs, TreeNode *node, int left) -> void
        {
            if (node == nullptr)
            {
                return;
            }
            path.push_back(node->val);
            left -= node->val;
            if (node->left == nullptr && node->right == nullptr && left == 0)
            {
                ans.push_back(path);
            }
            else
            {
                dfs(node->left, left);
                dfs(node->right, left);
            }
            path.pop_back(); // 恢复现场
        };
        dfs(root, targetSum);
        return res;
    }
};

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        recur(root, targetSum);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
    void recur(TreeNode *root, int tar)
    {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        tar -= root->val;
        if (tar == 0 && root->left == nullptr && root->right == nullptr)
        {
            res.push_back(path);
        }
        recur(root->left, tar);
        recur(root->right, tar);
        path.pop_back();
    }
};