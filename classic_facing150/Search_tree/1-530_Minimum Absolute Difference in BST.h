#include "..\..\head.h"

class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT_MAX;
        int pre = INT_MIN / 2;
        auto dfs = [&](this auto &&dfs, TreeNode *node) -> void
        {
            if (node == nullptr)
            {
                return;
            }
            dfs(node->left);
            ans = min(ans, node->val - pre);
            pre = node->val;
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }
};