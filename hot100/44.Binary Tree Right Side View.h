#include "..\head.h"

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        auto dfs = [&](this auto &&dfs, TreeNode *node, int depth) -> void
        {
            if (node == nullptr)
            {
                return;
            }
            if (depth == ans.size())
            {
                ans.push_back(node->val);
            }
            dfs(node->right, depth + 1);
            dfs(node->left, depth + 1);
        };
        dfs(root, 0);
        return ans;
    }
};