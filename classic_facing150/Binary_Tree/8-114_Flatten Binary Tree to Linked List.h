#include "..\..\head.h"

class Solution
{
private:
    TreeNode *head = nullptr;

public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        // 先递归处理右子树，再递归处理左子树, 确保在处理当前节点之前，其左右子树已经被展开为链表形式
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = head; // 将当前节点的右子节点指向 head（即之前已经展开的链表）
        head = root;        // 更新 head 为当前节点，因为当前节点现在是展开后的链表的新头部
    }
};

class Solution
{
    TreeNode *head;

public:
    void flatten(TreeNode *root)
    {
    }
};
