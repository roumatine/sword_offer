#include "face7.h"

void Test(char actual, char exp) {
    if (actual == exp) {
        cout << "Test passed\n" << endl;
    } else {
        cout << "Test failed\n "<< endl;
    }
}

int main() {
    CQue<char> que;
    que.appendTail('a');
    que.appendTail('b');
    que.appendTail('c');

    char head = que.deleteHead();
    Test(head, 'a');

    head = que.deleteHead();
    Test(head, 'b');

    head = que.deleteHead();
    Test(head, 'c');

    que.appendTail('d');
    head = que.deleteHead();
    Test(head, 'd');

    head = que.deleteHead();
    Test(head, 'e');

    return 0;
}