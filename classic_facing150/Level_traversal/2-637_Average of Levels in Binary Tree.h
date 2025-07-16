#include "..\..\head.h"

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<double> res;
        if (root != nullptr)
        {
            return que.push(root);
        }
        while (!que.empty())
        {
            int size = que.size();
            double sum = 0;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                sum += node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            res.push_back(sum / size);
        }
        return res;
    }
};