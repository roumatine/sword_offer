#include "..\head.h"

void move(vector<int> &src, vector<int> &tar) {
    // 从 src 顶部拿出一个圆盘
    int pan = src.back();
    src.pop_back();
    // 将圆盘放入 tar 顶部
    tar.push_back(pan);;
}

void dfs(int i, vector<int> &src, vector<int> &buf, vector<int> &tar) {
    if (i == 1) {
        move(src, tar);
        return;
    }
    // 子问题 f(i-1) ：将 src 顶部 i-1 个圆盘借助 tar 移到 buf
    dfs(i - 1, src, tar, buf);
    // 子问题 f(1) ：将 src 剩余一个圆盘移到 tar
    move(src, tar);
    // 子问题 f(i-1) ：将 buf 顶部 i-1 个圆盘借助 src 移到 tar
    dfs(i - 1, buf, src, tar);
}
void solveHanota(vector<int> &A, vector<int> &B, vector<int> &C) {
    int n = A.size();
    dfs(n, A, B, C);
}
