#include "..\head.h"

void find_continuous_sequence(int sum) {
    if (sum < 3) {
        return;
    }
    int small = 1;
    int big = 2;
    int mid = (sum + 1) / 2;
    int cur_sum = small + big;

    while (small < mid)
    {
        if (cur_sum == sum) {
            print_countinuous_sequence(small, big);
        }
        while (cur_sum > sum && small < mid) {
            cur_sum -= small;
            small++;
            if (cur_sum == sum) {
                print_countinuous_sequence(small, big);
            }
        }
        big++;
        cur_sum += big;
    }
    
}

void print_countinuous_sequence(int small, int big) {
    for (int i = small; i <= big; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}