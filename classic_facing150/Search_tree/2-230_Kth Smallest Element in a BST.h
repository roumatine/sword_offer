#include "..\..\head.h"

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int ans;
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
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int &k)
    { // 注意这里改成了引用
        if (root == nullptr)
        {
            return -1; // 题目保证节点值非负，用 -1 表示没有找到
        }
        int left_res = kthSmallest(root->left, k);
        if (left_res != -1) // 答案在左子树中
        {
            return left_res;
        }
        if (--k == 0) // 答案就是当前节点
        {
            return root->val;
        }
        return kthSmallest(root->right, k); // 右子树会返回答案或者 -1
    }
};
// class Solution
// {
// public:
//     int kthSmallest(TreeNode *root, int k)
//     {
//         auto dfs = [&](this auto &&dfs, TreeNode *node) -> int
//         {
//             if (node == nullptr)
//             {
//                 return -1; // 题目保证节点值非负，用 -1 表示没有找到
//             }
//             int left_res = dfs(node->left);
//             if (left_res != -1)
//             { // 答案在左子树中
//                 return left_res;
//             }
//             if (--k == 0)
//             { // 答案就是当前节点
//                 return node->val;
//             }
//             return dfs(node->right); // 右子树会返回答案或者 -1
//         };
//         return dfs(root);
//     }
// };

class Solution
{
private:
    int res = 0;
    int rank = 0;
    void traverse(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return;
        }

        traverse(root->left, k);

        rank++;
        if (k == rank)
        {
            res = root->val;
            return;
        }
        traverse(root->right, k);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        traverse(root, k);
        return res;
    }
};