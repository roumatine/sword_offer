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
    vector<vector<int>> decorateRecord(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root != nullptr) 
            q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            for (int i = q.size(); i > 0; i--) {
                root = q.front();
                q.pop();
                tmp.push_back(root->val);
                if (root->left != nullptr) 
                    q.push(root->left);
                if (root->right != nullptr)
                    q.push(root->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> decorateRecord(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *node;
        while (!q.empty()) {
            int cnt = q.size();
            vector<int> tmp;
            while (cnt --) {
                node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};