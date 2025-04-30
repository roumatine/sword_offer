
#include "..\head.h"

TreeLinkNode* get_next(TreeLinkNode *pNode) {
    if (pNode == nullptr)
        return nullptr
    
    if (pNode->right != nullptr) {
        pNode = pNode->right;
        while (pNode->left != nullptr) {
            pNode = pNode->left;
        }
        return pNode;
    }
    while (pNode->next != nullptr) {
        TreeLinkNode *pRoot = pNode->next;
        if (pRoot->left = pNode) {
            return pRoot;
        }
        pNode = pNode->next;
    }
    return nullptr;
}