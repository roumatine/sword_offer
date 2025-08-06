#include "..\head.h"

class LRUCache
{
public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node())
    {
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key)
    {
        Node *node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value)
    {
        Node *node = get_node(key);
        if (node)
        {
            node->value = value;
            return;
        }
        KeyToNode[key] = node = new Node(key, value);
        push_front(node);
        if (KeyToNode.size() > capacity)
        {
            Node *back_node = dummy->prev;
            KeyToNode.erase(back_node->key);
            remove(back_node);
            delete (back_node);
        }
    }

private:
    int capacity;
    Node *dummy;
    unordered_map<int, Node *> KeyToNode;

    void remove(Node *x)
    { // 删除一个节点（抽出一本书）
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    void push_front(Node *x)
    {
        // 在链表头添加一个节点（把一本书放到最上面）
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    Node *get_node(int key)
    {
        auto it = KeyToNode.find(key);
        if (it == KeyToNode.end())
        {
            return nullptr;
        }
        Node *node = it->second;
        remove(node);
        push_front(node);
        return node;
    }
};

class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int k = 0, int v = 0) : key(k), value(v) {}
};