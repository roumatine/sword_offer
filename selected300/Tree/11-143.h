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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) {
            return false;
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B) || HasSubTreeCore(A, B);
    }
    bool HasSubTreeCore(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == nullptr)
            return true;
        if (pRoot1 == nullptr)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;
        else 
            return HasSubTreeCore(pRoot1->left, pRoot2->left) && HasSubTreeCore(pRoot1->right, pRoot2->right); 
    }
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A != nullptr && B != nullptr) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
private:
    bool recur(TreeNode* A, TreeNode* B) {
        if(B == nullptr) return true;
        if(A == nullptr || A->val != B->val) return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};