#include "..\head.h"

class tmp {
public:
    tmp() {
        ++ N;
        sum += N;
    }
    static void reset() {
        N = 0;
        sum = 0;
    }
    static unsigned int getsum() {
        return sum;
    }

private:
    static unsigned int N;
    static unsigned int sum;
};

unsigned int tmp::N = 0;
unsigned int tmp::sum = 0;

unsigned int sum_solution1(unsigned int n) {
    tmp::reset();

    tmp *a = new tmp[n];
    delete[] a;
    a = nullptr;
    return tmp::getsum();
}