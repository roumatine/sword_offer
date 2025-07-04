#include "..\..\head.h"

class Node
{
public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int k = 0, int v = 0) : key(k), val(v) {}
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
    }

    int get(int key)
    {
    }

    void put(int key, int value)
    {
    }

private:
    int cap;
    Node *dummy;
    unordered_map<int, Node *> KeytoNode;

    void revmove(Node *x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }
    void push_front(Node *x)
    {
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }
    Node *Get_node(int key)
    {
    }
};
