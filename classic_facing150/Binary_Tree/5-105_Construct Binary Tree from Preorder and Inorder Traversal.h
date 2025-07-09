#include "..\..\head.h"

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
        {
            return nullptr;
        }
        int size = ranges::find(inorder, preorder[0]) - inorder.begin();
        // 将前序和中序序列分割为左子树和右子树的子序列。
        vector<int> pre1(preorder.begin() + 1, preorder.begin() + 1 + size); // 因为左子树有 size个节点
        vector<int> pre2(preorder.begin() + 1 + size, preorder.end());
        vector<int> ino1(inorder.begin(), inorder.begin() + size);
        vector<int> ino2(inorder.begin() + 1 + size, inorder.end());
        TreeNode *left = buildTree(pre1, ino1);
        TreeNode *right = buildTree(pre2, ino2);
        return new TreeNode(preorder[0], left, right);
    }
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 构建中序遍历的哈希表，方便快速查找根节点位置
        for (int i = 0; i < inorder.size(); ++i)
        {
            unmp[inorder[i]] = i;
        }
    }

private:
    unordered_map<int, int> unmp;
    TreeNode *build(vector<int> &preorder, int pre_start, int pre_end,
                    vector<int> &inorder, int ino_start, int ino_end)
    {
        if (pre_start > pre_end || ino_start > ino_end)
        {
            return nullptr; // 终止条件：先序遍历或中序遍历的区间为空
        }
        int root_val = preorder[pre_start];
        TreeNode *root = new TreeNode(root_val);
        int root_pos = unmp[root_val];
        int left_size = root_pos - ino_start;
        root->left = build(preorder, pre_start + 1, pre_start + left_size, inorder, ino_start, root_pos - 1);
        root->right = build(preorder, pre_start + left_size + 1, pre_end, inorder, root_pos + 1, ino_end);
        return root;
    }
};
