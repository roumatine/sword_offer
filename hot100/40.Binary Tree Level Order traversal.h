#include "..\head.h"

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    { // 广度优先遍历 -> 层序遍历
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> ans;
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
            ans.emplace_back(vals);
        }
        return ans;
    }

    vector<vector<int>> levelOrder_que(TreeNode *root)
    { // queue 代替两个数组
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> ans;
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
            ans.emplace_back(vals);
        }
        return ans;
    }
};