#include "..\head.h"
int max_value = 6;

void print_probability(int num) {
    if (num < 1) {
        return;
    }

    int *probabilities[2];
    probabilities[0] = new int[max_value * num + 1];
    probabilities[1] = new int[max_value * num + 1];

    for (int i = 0; i < max_value * num + 1; i++) {
        probabilities[0][i] = 0;
        probabilities[1][i] = 0;
    }
    int flag = 0;
    for (int i = 1; i < max_value; i++) {
        probabilities[flag][i] = 1;
    }
    for (int k = 2; k <= num; k++) {
        for (int i = 0; i < k; i++) {
            probabilities[1 - flag][i] = 0;
            for (int j = 1; j <= i && j <= max_value; j++) {
                probabilities[1 - flag][i] += probabilities[flag][i - j];
            }
        }
        flag = 1 - flag;
    }

    double total = pow((double)max_value, num);
    for (int i = num; i < max_value * num + 1; i++) {
        double radio = (double)probabilities[flag][i] / total;
        printf("%d: %.6f\n", i, radio);
    }
    
    delete[] probabilities[0];
    delete[] probabilities[1];
}