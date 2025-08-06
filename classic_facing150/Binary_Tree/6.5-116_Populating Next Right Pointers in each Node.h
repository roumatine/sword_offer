#include "..\..\head.h"

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution1
{ // dfs
private:
    vector<Node *> pre;
    void dfs(Node *node, int dep)
    {
        if (node == nullptr)
        {
            return;
        }
        if (dep == pre.size())
        { // node 是这一层最左边的节点
            pre.push_back(node);
        }
        else
        {                          // pre[depth] 是 node 左边的节点
            pre[dep]->next = node; // node 左边的节点指向 node
            pre[dep] = node;
        }
        dfs(node->left, dep + 1);
        dfs(node->right, dep + 1);
    }

public:
    Node *connect(Node *root)
    {
        dfs(root, 0);
        return root;
    }
};

class Solution2
{ // bfs
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        vector<Node *> q = {root};
        while (!q.empty())
        {
            vector<Node *> nxt;
            for (int i = 0; i < q.size(); ++i)
            {
                Node *node = q[i];
                if (i)
                {
                    q[i - 1]->next = node;
                }
                if (node->left)
                {
                    nxt.push_back(node->next);
                }
                if (node->left)
                {
                    nxt.push_back(node->right);
                }
            }
            q = move(nxt);
        }
        return root;
    }
};
