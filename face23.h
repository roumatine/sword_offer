#include "face18.h"
#include <deque>

void PrintFromTop2Bottom(BinaryTreeNode* pROot) {
    if (pROot == nullptr) {
        return;
    }

    std::deque<BinaryTreeNode*> dequeTreeNode; // 双端队列

    dequeTreeNode.push_back(pROot);

    while (dequeTreeNode.size()) {
        BinaryTreeNode *pNode = dequeTreeNode.front(); 
        dequeTreeNode.pop_front(); 

        std::cout << pNode->m_value << " ";
        if (pNode->m_pleft) {
            dequeTreeNode.push_back(pNode->m_pleft);
        }
        if (pNode->m_pright) {
            dequeTreeNode.push_back(pNode->m_pright);
        }
    }
}
