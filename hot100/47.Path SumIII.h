#include "..\head.h"

class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        int ans = 0;
        unordered_map<long long, int> cnt{{0, 1}};
        auto dfs = [&](this auto &&dfs, TreeNode *node, long long s)
        {
            if (node == nullptr)
            {
                return;
            }
            s += node->val;
            ans += cnt[s - targetSum];
            cnt[s]++;
            dfs(node->left, s);
            dfs(node->right, s);
            cnt[s]--;
        };
        dfs(root, 0);
        return ans;
    }
};