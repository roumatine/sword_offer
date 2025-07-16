#include "..\..\head.h"

class BSTIterator
{
private:
    vector<TreeNode *> vec;

public:
    BSTIterator(TreeNode *root)
    {
        dfsLeft(root);
    }

    int next()
    {
        TreeNode *root = vec.back();
        vec.pop_back();
        int ans = root->val;
        root = root->right;
        dfsLeft(root);
        return ans;
    }

    bool hasNext()
    {
        return !vec.empty();
    }
    void dfsLeft(TreeNode *root)
    {
        while (root)
        {
            vec.push_back(root);
            root = root->left;
        }
    }
};