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
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> pathTarget(TreeNode* root, int target) {
        recur(root, target);
        return res;
    }
private:
    
    void recur(TreeNode* root, int target) {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        target -= root->val;
        if (target == 0 && root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
        }
        recur(root->left, target);
        recur(root->right, target);
        path.pop_back();
    }
};

class solution {
vector<vector<int>> res;
vector<int> path;
public:
    void pathSumcore(TreeNode *root, int target) {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        if (target == root->val && root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
        } else {
            if (root->left != nullptr)
                pathSumcore(root->left, target - root->val);
            if (root->right != nullptr)
                pathSumcore(root->right, target - root->val);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        if (root == nullptr)
            return res;
        pathSumcore(root, target);
        return res;
    }
};