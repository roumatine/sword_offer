#include "face18.h"

void FindPath(BinaryTreeNode* pRoot, int expSum) {
    if (pRoot == nullptr) {
        return;
    }
    std::vector<int> path;
    int currSum = 0;
    FindPath(pRoot, expSum, path, currSum);
}

void FindPath(BinaryTreeNode* pRoot, int expSum, 
    std::vector<int>& path, int& currSum) {
        currSum += pRoot->m_value;
        path.push_back(pRoot->m_value);

        bool ifleaves = pRoot->m_pleft == nullptr && pRoot->m_pright == nullptr;
        if (currSum == expSum && ifleaves) {
            std::cout << "A path is found: ";
            std::vector<int>::iterator iter = path.begin(); // begin()返回指向第一个元素的迭代器
            for (; iter != path.end(); ++iter) {
                // printf("%d\t", *iter);
                // printf("\n");
                std::cout << *iter << " " << std::endl;
            }
        }
        if (pRoot->m_pleft != nullptr) {
            FindPath(pRoot->m_pleft, expSum, path, currSum);
        }
        if (pRoot->m_pright != nullptr) {
            FindPath(pRoot->m_pright, expSum, path, currSum);
        }
        currSum -= pRoot->m_value;
        path.pop_back();
    }