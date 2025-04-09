#include "..\head.h"

class ArrayBinaryTree {
public:
    ArrayBinaryTree(vector<int> arr) {
        tree = arr;
    }

    int size() {
        return tree.size();

    }

    int val(int i) {
        if (i < 0 || i > size()) {
            return INT_MAX;
        }
        return tree[i];
    }

     /* 获取索引为 i 节点的左子节点的索引 */
    int left(int i) {
        return 2 * i + 1;
    }

    /* 获取索引为 i 节点的右子节点的索引 */
    int right(int i) {
        return 2 * i + 2;
    }

     /* 获取索引为 i 节点的父节点的索引 */
    int parent(int i) {
        return (i - 1) / 2;
    }

    vector<int> levelOrder() {
        vector<int> res;
        // 直接遍历数组
        for (int i = 0; i < size(); i++) {
            if (val(i) != INT_MAX)
                res.push_back(val(i));
        }
        return res;
    }

    /* 前序遍历 */
    vector<int> preOrder() {
        vector<int> res;
        dfs(0, "pre", res);
        return res;
    }

    /* 中序遍历 */
    vector<int> inOrder() {
        vector<int> res;
        dfs(0, "in", res);
        return res;
    }

    /* 后序遍历 */
    vector<int> postOrder() {
        vector<int> res;
        dfs(0, "post", res);
        return res;
    }

private:
    vector<int> tree;

     /* 深度优先遍历 */
    void dfs(int i, string order, vector<int> &res) {
        // 若为空位，则返回
        if (val(i) == INT_MAX)
            return;
        // 前序遍历
        if (order == "pre")
            res.push_back(val(i));
        dfs(left(i), order, res);
        // 中序遍历
        if (order == "in")
            res.push_back(val(i));
        dfs(right(i), order, res);
        // 后序遍历
        if (order == "post")
            res.push_back(val(i));
    }
};