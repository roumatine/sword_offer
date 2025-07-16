#include "..\..\head.h"

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> res;
        vector<TreeNode *> cur = {root};
        while (!cur.empty())
        {
            vector<TreeNode *> nxt;
            vector<int> tmp;
            for (auto node : cur)
            {
                tmp.push_back(node->val);
                if (node->left)
                {
                    nxt.push_back(node->left);
                }
                if (node->right)
                {
                    nxt.push_back(node->right);
                }
            }
            cur = move(nxt);
            if (res.size() % 2)
            {
                ranges::reverse(tmp);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
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
            vector<int> tmp;
            for (int i = que.size(); i--;)
            {
                auto node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            if (res.size() % 2)
            {
                ranges::reverse(tmp);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};