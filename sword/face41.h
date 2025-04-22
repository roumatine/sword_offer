#include "..\head.h"

bool find_nums_with_sum(int data[], int len, int sum, int *num1, int *num2) {
    bool found = false;
    if (len < 1 || num1 == nullptr || num2 == nullptr) {
        return found;
    }
    int ahead = len - 1;
    int behind = 0;

    while (ahead > behind) {
        long long cur_sum = data[ahead] + data[behind];
        if (cur_sum == sum) {
            *num1 = data[behind];
            *num2 = data[ahead];
            found = true;
            break;
        } else if (cur_sum > sum) {
            ahead--;
        } else {
            behind++;

        }
    }
    return found;
}