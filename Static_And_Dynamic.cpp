#include "head.h"

class A {
public :
/* virtual*/
    void func() {
        std::cout << "A::func() " << std::endl;
    }
};

class B : public A {
public :
    void func() {
        std::cout << "B::func() " << std::endl;
    }
};

class C : public A {
public :
    void func() {
        std::cout << "C::func() " << std::endl;
    }
};

int main() {
    C* pc = new C();
    B* pb = new B();
    A* pa = pc;
    pa = pb;
    C* pnull = nullptr;

    pa->func();
    pc->func();
    pnull->func();
    return 0;
}