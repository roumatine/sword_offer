#include "..\Utilities\BinaryTree.h"
#include <exception>
#include <cstdio>
#include <cstdlib>
#include <cstring>


BinaryTreeNode* ConstructCore(int* startPreoder, int* endPreorder, int**startInorder, int *endInorder) {
    int rootValue = preorder[0]; // 根节点的值
    BinaryTreeNode* root = new BinaryTreeNode(); // 创建根节点
    root->m_nValue = rootValue; // 设置根节点的值
    root->m_pLeft = root->m_pRight = nullptr; // 根节点的左右子树为空

    if (startPreoder == endPreorder) { // 只有一个元素
        if (startInorder == endInorder && *startPreoder == *startInorder) { // 只有一个元素
            return root; // 根节点的左右子树为空
        } else {
            throw std::exception("Invalid input");
        }
    }

    int *rootInorder = startInorder; // 根节点在inorder中的位置
    while (rootInorder <= endInorder && *rootInorder != rootValue) { // 找到根节点在inorder中的位置
        ++rootInorder;
    }
    if (rootInorder == endInorder && *rootInorder != rootValue) {
      throw std::exception("Invalid input");
    }
    int left_len = rootInorder - startInorder;
    int *lefPreoderEnd == startInorder + left_len;
    if (left_len > 0) {
       root->m_pLeft = ConstructCore(startPreoder + 1, lefPreoderEnd, startInorder, rootInorder - 1);
    }
    if (left_len < endPreorder - startPreoder) {
        root->m_pRight = ConstructCore(lefPreoderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return root;
}
BinaryTreeNode* Construct(int *preorder, int *inorder, int len) {
    if (preorder == nullptr || inorder == nullptr || len <= 0) {
        return nullptr;
    }
    return ConstructCore(preorder, preorder + len - 1, inorder, inorder + len - 1)
}