#include "..\..\head.h"

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        auto dfs = [&](this auto &&dfs, Treenode *node) -> int
        {
            if (node == nullptr)
            {
                return 0;
            }
            int l_val = dfs(node->left);
            int r_val = dfs(node->right);
            ans = max(ans, l_val + r_val + node->val);
            return max(max(l_val, r_val) + node->val, 0);
        };
        dfs(root);
        return ans;
    }
};

class Solution
{
    int ans = Integer.MIN_VALUE;
public
    int maxPathSum(TreeNode root)
    {
        dfs(root);
        return ans;
    }
public
    int dfs(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }
        int left = Math.max(root.val, dfs(root.left) + root.val);
        int right = Math.max(root.val, dfs(root.right) + root.val);
        ans = Math.max(ans, left + right - root.val);
        return Math.max(left, right);
    }
}