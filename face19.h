#include "head.h"
#include "face18.h"

void MirrorRecursively(BinaryTreeNode *pNode) {
    if ((pNode == nullptr) || (pNode->m_pleft == nullptr && pNode->m_pright)) {
        return;
    }

    BinaryTreeNode *pTemp = pNode->m_pleft;
    pNode->m_pleft = pNode->m_pright;
    pNode->m_pright = pTemp;
    if (pNode->m_pleft) {
        MirrorRecursively(pNode->m_pleft);
    }
    if (pNode->m_pright) {
        MirrorRecursively(pNode->m_pright);
    }
}

void MirrorIteratively(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    std::stack<BinaryTreeNode*> stackTreeNode;
    stackTreeNode.push(pRoot);

    while(stackTreeNode.size()) {
        BinaryTreeNode *pNode = stackTreeNode.top();
        stackTreeNode.pop();

        if (pNode->m_pleft) {
            stackTreeNode.push(pNode->m_pleft);
        }
        if (pNode->m_pright) {
            stackTreeNode.push(pNode->m_pright);
        }
    }

}