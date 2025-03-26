#include "face26.h"

void CloneNode(ComplexListNode* pHead) {
    ComplexListNode* pNode = pHead;
    while (pNode != nullptr) {
        ComplexListNode* pClone = new ComplexListNode();
        pClone->nValue = pNode->nValue;
        pClone->p_Next = pNode->p_Next;
        pClone->pSibling = nullptr;
        
        pNode->p_Next = pClone;
        pNode = pClone->p_Next;
    }
}

void ConnectSiblingNodes(ComplexListNode* pHead) {
    ComplexListNode* pNode = pHead;
    while (pNode != nullptr) {
        ComplexListNode* pClone = pNode->p_Next;
        if (pNode->pSibling != nullptr) {
            pClone->pSibling = pNode->pSibling->p_Next;
        }
        pNode = pClone->p_Next;
    }
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
    ComplexListNode* pNode = pHead;
    ComplexListNode* pCloneHead = nullptr;
    ComplexListNode* pCloneNode = nullptr;

    if (pNode != nullptr) {
        pCloneHead = pCloneNode = pNode->p_Next;
        pNode->p_Next = pCloneNode->p_Next;
        pNode = pNode->p_Next;
    }
    while (pNode != nullptr) {
        pCloneNode->p_Next = pNode->p_Next;
        pCloneNode = pCloneNode->p_Next;

        pNode->p_Next = pCloneNode->p_Next;
        pNode = pNode->p_Next;
    }
    return pCloneHead;
}

ComplexListNode* Clone(ComplexListNode* pHead) {
    CloneNode(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}



void Test(const char* testName, ComplexListNode* pHead)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode* pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNode(pNode1, pNode2, pNode3);
    BuildNode(pNode2, pNode3, pNode5);
    BuildNode(pNode3, pNode4, nullptr);
    BuildNode(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNode(pNode1, pNode2, nullptr);
    BuildNode(pNode2, pNode3, pNode5);
    BuildNode(pNode3, pNode4, pNode3);
    BuildNode(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNode(pNode1, pNode2, nullptr);
    BuildNode(pNode2, pNode3, pNode4);
    BuildNode(pNode3, pNode4, nullptr);
    BuildNode(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
    ComplexListNode* pNode1 = CreateNode(1);
    BuildNode(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

