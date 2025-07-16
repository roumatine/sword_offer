#include "..\..\head.h"
// 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
// 并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层（从第 0 层开始），则该层包含 1~ 2^h 个节点。
// 满二叉树如下图，是一种特殊的完全二叉树，每层都是是满的,像一个稳定的三角形

// 一个普通二叉树，显然只要向下面这样遍历一边即可，时间复杂度 O(N)
// public int countNodes(TreeNode root)
// {
//     if (root == null)
//         return 0;
//     return 1 + countNodes(root.left) + countNodes(root.right);
// }

// 那如果是一棵满二叉树，节点总数就和树的高度呈指数关系
// public int countNodes(TreeNode root)
// {
//     int h = 0;
//     // 计算树的高度
//     while (root != null)
//     {
//         root = root.left;
//         h++;
//     }
//     // 节点总数就是 2^h - 1
//     return (int)Math.pow(2, h) - 1;
// }

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left_levels = countLevels(root->left);
        int right_levels = countLevels(root->right);
        if (left_levels == right_levels)
        {                                                        // (1 << levels)是位运算，等价于2^levels
            return countNodes(root->right) + (1 << left_levels); // 递归计算右子树的节点数 + 计算左子树的节点数（2^h - 1）+根节点（=2^h）
        }
        else
        {
            return countNodes(root->left) + (1 << right_levels); // 递归计算左子树的节点数 + 计算右子树的节点数（2^h - 1）+根节点（=2^h）
        }
    }

private:
    int countLevels(TreeNode *root) // 统计树的深度
    {
        int levels = 0;
        while (root)
        {
            root = root->left;
            levels += 1;
        }
        return levels;
    }
};