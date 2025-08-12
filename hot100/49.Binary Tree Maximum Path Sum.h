#include "..\head.h"

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        auto dfs = [&](this auto &&dfs, TreeNode *node) -> int
        {
            if (node == nullptr)
            {
                return 0;
            }
            int left_val = dfs(node->left);
            int right_val = dfs(node->right);
            ans = max(ans, left_val + right_val + node->val);
            return max(max(left_val, right_val) + node->val, 0);
        };
        dfs(root);
        return ans;
    }
};