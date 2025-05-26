#include "head.h"

class A {
public:
    A() {
        cout << "默认构造函数 A()" << endl;
    }
    A(int a) {
        value = a;
        cout << " A(int " << value << ")" << endl;
    }
    A(const A& a) {
        value = a.value;
        cout << "拷贝构造函数 A(A& a)" << value << endl;
    }
    int value;
};

class B {
public :
    B() : a(1) {
        b = A(2);
    }
    A a;
    A b;
};

int main() {
    B b;
}