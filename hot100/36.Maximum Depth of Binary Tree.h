#include "..\head.h"

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int l_depth = maxDepth(root->left);
        int r_depth = maxDepth(root->right);
        return max(l_depth, r_depth) + 1;
    }

    int maxDepth(TreeNode *root)
    {
        int ans = 0;
        auto dfs = [&](this auto &&dfs, TreeNode *node, int depth) -> void
        {
            if (node == nullptr)
            {
                return;
            }
            depth++;
            ans = max(ans, depth);
            dfs(node->left, depth);
            dfs(node->right, depth);
        };
        dfs(root, 0);
        return ans;
    }
};