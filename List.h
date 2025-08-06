#pragma once

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
struct Listnode
{
    int val;
    struct Listnode *next;
    Listnode(int x) : val(x), next(nullptr) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
        next = nullptr;
        random = nullptr;
    }
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

__declspec(dllexport) ListNode *CreateListNode(int value);
__declspec(dllexport) void ConnectListNodes(ListNode *pCurrent, ListNode *pNext);
__declspec(dllexport) void PrintListNode(ListNode *pNode);
__declspec(dllexport) void PrintList(ListNode *pHead);
__declspec(dllexport) void DestroyList(ListNode *pHead);
__declspec(dllexport) void AddToTail(ListNode **pHead, int value);
__declspec(dllexport) void RemoveNode(ListNode **pHead, int value);