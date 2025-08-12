#include "..\head.h"

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size())
        {
            return nullptr;
        }
        int left_size = ranges::find(inorder, preorder[0]) - inorder.begin();
        vector<int> pre1(preorder.begin() + 1, preorder.begin() + 1 + left_size);
        }
};