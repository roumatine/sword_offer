#include "..\head.h"

struct treeNode {
    int val;          // 节点值
    treeNode *left;   // 左子节点指针
    treeNode *right;  // 右子节点指针
    treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

treeNode* n1 = new treeNode(1);
treeNode* n2 = new treeNode(2);
treeNode* n3 = new treeNode(3);
treeNode* n4 = new treeNode(4);
treeNode* n5 = new treeNode(5);
// 构建节点之间的引用（指针）
n1->left = n2;
n1->right = n3;
n2->left = n4;
n2->right = n5;

/* 插入与删除节点 */
treeNode* P = new treeNode(0);
// 在 n1 -> n2 中间插入节点 P
n1->left = P;
P->left = n2;
// 删除节点 P
n1->left = n2;
// 释放内存
delete P;