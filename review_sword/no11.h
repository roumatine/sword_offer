#include "..\head.h"

int numof1(int n) {
    return bitset<32>(n).count();
}


int num_of_1(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n = n & (n - 1);

    }
    return count
}