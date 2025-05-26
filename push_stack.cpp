#include "head.h"

int f(int n) {
    cout << n << endl;
    return n;
}

void func(int p1, int p2) {
    int var1 = p1;
    int var2 = p2;
    printf("var1 = %d, var2 = %d\n", f(var1), f(var2));
}

int main(int argc, char * argv[]) {
    func(1, 2);
    return 0;
}