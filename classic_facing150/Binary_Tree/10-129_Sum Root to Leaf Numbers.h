#include "..\..\head.h"

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode *root, int prev)
    {
        if (root = nullptr)
        {
            return 0;
        }
        int prev = prev * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            return prev;
        }
        else
        {
            return dfs(root->left, prev) + dfs(root->right, prev);
        }
    }
};

class Solution1
{
public:
    int sumNumbers(TreeNode *root, int x = 0)
    {
        if (root = nullptr)
        {
            return 0;
        }
        x = x * 10 + root->val;
        if (oot->left == nullptr && root->right == nullptr)
        {
            return x;
        }
        return sumNumbers(root->left, x) + sumNumbers(root->right, x);
    }
}

class Solution2
{
public:
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        auto dfs = [&](this auto &&dfs, TreeNode *node, int x) -> void
        {
            if (node == nullptr)
            {
                return;
            }
            x = x * 10 + node->val;
            if (node->left == nullptr && node->right == nullptr)
            { // node 是叶子节点
                ans += x;
                return;
            }
            dfs(node->left, x);
            dfs(node->right, x);
        };
        dfs(root, 0);
        return ans;
    }
};

// class Solution
// {
// public
//     int sumNumbers(TreeNode root)
//     {
//         if (root == null)
//             return 0;
//         if (root.left == root.right)
//             return root.val;
//         if (root.left != null)
//             root.left.val = root.val * 10 + root.left.val;
//         if (root.right != null)
//             root.right.val = root.val * 10 + root.right.val;
//         return sumNumbers(root.left) + sumNumbers(root.right);
//     }
// };