#pragma once

#include <vector>

struct TreeNode
{
    int m_nValue;
    std::vector<TreeNode *> m_vChildren;
};

struct treeNode
{
    int val;         // 节点值
    treeNode *left;  // 左子节点指针
    treeNode *right; // 右子节点指针
    treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

__declspec(dllexport) TreeNode *CreateTreeNode(int value);
__declspec(dllexport) void ConnectTreeNodes(TreeNode *pParent, TreeNode *pChild);
__declspec(dllexport) void PrintTreeNode(const TreeNode *pNode);
__declspec(dllexport) void PrintTree(const TreeNode *pRoot);
__declspec(dllexport) void DestroyTree(TreeNode *pRoot);