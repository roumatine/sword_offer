#include "head.h"
class A {
public:
    A() {printf("A\n");}
    virtual ~A() {printf("~A\n");}
    virtual void foo() {printf("A::foo\n");}
    
};
class B : public A {
public:
    B() {printf("B\n");}
    ~B() {printf("~B\n");}
    void foo() {printf("B::foo\n");}
};

int main() {
    A *p = new B();
    p->foo();
    delete p;
}