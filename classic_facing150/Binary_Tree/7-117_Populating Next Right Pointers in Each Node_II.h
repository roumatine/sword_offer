#include "..\..\head.h"

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{ // dfs
public:
    Node *connect(Node *root)
    {
        dfs(root, 0);
        return;
    }

private:
    vector<Node *> pre;
    void dfs(Node *node, int depth)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (depth == pre.size())
        {
            pre.push_back(node);
        }
        else
        {
            pre[depth]->next = node;
            pre[depth] = node;
        }
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};

class Solution
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
                    nxt.push_back(node->left);
                }
                if (node->right)
                {
                    nxt.push_back(node->right);
                }
            }
            q = move(nxt);
        }
        return root;
    }
};