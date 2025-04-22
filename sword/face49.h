#include "..\head.h"

class A {

private:
    int n1;
    int n2;
public:
    A() : n2(0), n1(n2 + 2) {}
    // n2 = 0 , n1 为随机值

    void print() {
        std::cout << "n1: " << n1 << " n2: " << n2 << std::endl;
    }
};

int _tmain(int argc, _TCHAR* argv[]) {
    A a;
    a.print();
    return 0;
}