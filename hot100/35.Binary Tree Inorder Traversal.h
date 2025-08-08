#include "..\head.h"

class Solution
{
private:
    void inorder_traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
        {
            return;
        }
        inorder_traversal(cur->left, vec);
        vec.push_back(cur->val);
        inorder_traversal(cur->right, vec);
    }

public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return ans;
        }
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        inorder_traversal(root, res);
        return res;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return ans;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
    }
};