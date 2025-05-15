#include "..\..\head.h"

struct TreeNode {
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> unmp;
        for (int i = 0; i < preorder.size(); i++) {
            unmp.insert({inorder[i], i});
        }
        return Build(preorder, unmp, 0, 0, inorder.size() - 1);
    }
    TreeNode *Build(vector<int> preorder, unordered_map<int, int> &unmp; int pre_root, int in_start, int in_end) {
        if (in_start > in_end)
            return nullptr;
        TreeNode* tree = new TreeNode(preorder[pre_root]);
        int in_root_index = unmp[preorder[pre_root]];
        
        tree->left = Build(preorder, unmp, pre_root + 1, in_start, in_root_index - 1);
        tree->right = Build(preorder, unmp, (pre_root + 1) + (in_root_index - 1 - in_start) + 1, in_root_index + 1, in_end);
    }
};