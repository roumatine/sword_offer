#include "head.h"

// BST
bool VerifySquenceOfBST(int sequence[], int len) {
    if (sequence == nullptr || len <= 0) {
        return false;
    }

    int root = sequence[len - 1];

    int i = 0;
    for (; i < len - 1; ++i) {
        if (sequence[i] > root) {
            break;
        }
    }
    int j = i;
    for (; j < len - 1; ++j) {
        if (sequence[j] < root) {
            return false;
        }
    }
    bool left = true;
    if (i > 0) {
        left = VerifySquenceOfBST(sequence, len - i - 1); // 递归判断左子树
    }

    bool right = true;
    if (i < len - 1) {
        right = VerifySquenceOfBST(sequence + i, len - i - 1); // 递归判断右子树
    }
    return (left && right);
}