#include "..\head.h"

void find_nums_appear_once(int data[], int len, int *num1, int *num2) {
    if (data == nullptr || len < 2) {
        return;
    }
    int result_exclusive_or = 0;
    for (int i = 0; i < len; ++i) {
        result_exclusive_or ^= data[i];
    }

    unsigned int index_of_1 = find_first_bit_is1(result_exclusive_or);

    *num1 = *num2 = 0;
    for (int j = 0; j < len; ++j) {
        if (is_bit_1(data[j], index_of_1)) {
            *num1 ^= data[j];
        } else {
            *num2 ^= data[j];

        }
    }
}

unsigned int find_first_bit_is1(int num) {
    int index_bit = 0;
    while ((num & 1) == 0 && (index_bit < 8 * sizeof(int))) {
        num = num >> 1;
        ++index_bit;
    }
    return index_bit;
}

bool is_bit_1(int num, unsigned int index_bit) {
    num = num >> index_bit;
    return (num & 1);
}