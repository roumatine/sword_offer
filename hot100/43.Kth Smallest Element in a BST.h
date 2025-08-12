#include "..\head.h"

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return -1;
        }
        int left_res = kthSmallest(root->left, k);
        if (left_res != -1)
        {
            return left_res;
        }
        if (--k == 0)
        {
            return root->val;
        }
        return kthSmallest(root->right, k);
    }

    int kthSmallest_1(TreeNode *root, int &k)
    {
        int ans = 0;
        auto dfs = [&](this auto &&dfs, TreeNode *node) -> void
        {
            if (node == nullptr || k == 0)
            {
                return;
            }
            dfs(node->left);
            if (--k == 0)
            {
                ans = node->val;
            }
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }

private:
    int rank = 0;
    int k;
    int res;
    int kthSmallest(TreeNode *root, int k)
    {
        this->k = k;

        traverse(root);

        return res;
    }

    void traverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        traverse(root->left);

        rank++;

        if (rank == k)
        {
            res = root->val;
            return;
        }

        traverse(root->right);
    }
};