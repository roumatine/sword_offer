#include "..\head.h"

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        auto dfs = [&](this auto &&dfs, TreeNode *node) -> int
        {
            if (node == nullptr)
            {
                return -1;
            }
            int l_len = dfs(node->left);
            int r_len = dfs(node->right);
            ans = max(ans, l_len + r_len + 2);
            return max(l_len, r_len) + 1;
        };
        dfs(root);
        return ans;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        auto dfs = [&](this auto &&dfs, TreeNode *node) -> int
        {
            if (node == nullptr)
            {
                return -1;
            }
            int l_len = dfs(node->left) + 1;
            int r_len = dfs(node->right) + 1;
            ans = max(ans, l_len + r_len);
            return max(l_len, r_len);
        };
        dfs(root);
        return ans;
    }
};