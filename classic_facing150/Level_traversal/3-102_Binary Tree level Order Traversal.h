#include "..\..\head.h"

class Solution
{ // 层序遍历:即逐层地，从左到右访问所有节点
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> res;
        vector<TreeNode *> cur = {root};
        while (cur.size())
        {
            vector<TreeNode *> nxt;
            vector<int> vals;
            for (auto node : cur)
            {
                vals.push_back(node->val);
                if (node->left)
                    nxt.push_back(node->left);
                if (node->right)
                    nxt.push_back(node->right);
            }
            cur = move(nxt);
            res.emplace_back(vals);
        }
        return res;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            vector<int> vals;
            for (int n = que.size(); n--;)
            {
                auto node = que.front();
                que.pop();
                vals.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            res.emplace_back(vals);
        }
        return res;
    }
};