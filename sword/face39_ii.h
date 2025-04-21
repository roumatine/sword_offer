#include "..\head.h"

bool is_balanced(BinaryTreeNode *pRoot, int *pDepth)
{
    if(pRoot == nullptr){
        *pDepth = 0;
        return true;
    }
    int left, right;
    if (is_balanced(pRoot->m_pLeft, &left) && is_balanced(pRoot->m_pRight, &right))  {
        int diff = left - right;
        if (diff <= 1 && diff >= -1) {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}