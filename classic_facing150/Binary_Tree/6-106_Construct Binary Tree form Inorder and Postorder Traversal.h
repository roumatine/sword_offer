#include "..\..\head.h"

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.empty())
        {
            return nullptr;
        }
        int left_size = ranges::find(inorder, postorder.back(1)) - inorder.begin();
        vector<int> ino1(inorder.begin(), ino1.begin() + left_size);
        vector<int> ino2(inorder.begin() + left_size + 1, inorder.end());
        vector<int> post1(postorder.begin(), postorder.begin() + left_size);
        vector<int> post2(postorder.begin() + left_size, postorder.end() - 1);
        auto left = buildTree(ino1, post1);
        auto right = buildTree(ino2, post2);
        return new TreeNode(postorder.back(), left, right);
    }
};