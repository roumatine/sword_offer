/*
no.23 二叉搜索树的后序遍历序列
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则返回 true ,否则返回 false 。假设输入的数组的任意两个数字都互不相同。
*/
#include "..\head.h"

bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.empty())
        return false;
    if (sequence.size() == 1)
        return true;
    return VerifySquenceOfBSTCore(sequence, 0, sequence.size() - 1);
}

bool VerifySquenceOfBSTCore(vector<int> &sequence, int start, int end) {
    if (start >= end)
        return true;
    int low = start;
    while (low < end && sequence[low] < sequence[end]) {
        low ++;
    }
    for (int i = low; i < end; ++i) {
        if (sequence[i] <= sequence[end]) {
            return false;
        }
    }
    return VerifySquenceOfBSTCore(sequence, start, low - 1) && // 判断当前节点是左子树
        VerifySquenceOfBSTCore(sequence, low, end - 1); // 判断当前节点是右子树
}