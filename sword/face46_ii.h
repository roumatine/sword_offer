#include "..\head.h"


typedef unsigned int (*fun)(unsigned int);
unsigned int solution_teminator(unsigned int n) {
    return 0;
}

unsigned int sum_solution3(unsigned int n ) {
    static fun f[2] = {solution_teminator, sum_solution3};
    return n + f[!!n](n - 1);
}
