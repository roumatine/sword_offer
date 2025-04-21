#include "..\head.h"

int max_value = 6;

void probability(int num, int *probabilities) {
    for (int i = 0; i < max_value; i++) {
        probability(num, num, i, probabilities);
    }
}

void probability(int original, int cur, int sum, int *probabilities) {
    if (cur == 1) {
        probabilities[sum - original] ++;
    } else {
        for (int i = 1; i < max_value; i++) {
            probability(original, cur - 1, sum + i, probabilities);
        }
    }
}

void print_probability(int num) {
    if (num < 1) {
        return;
    }
    int maxsum = num * max_value;
    int *probabilities = new int[maxsum - num + 1];
    for (int i = 0; i <=  maxsum ; i++) {
        probabilities[i - num] = 0;
    }
    probability(num, probabilities);
    int total = pow((double)max_value, num);
    for (int i = num; i < maxsum; i++) {
        double radio = (double)probabilities[i - num] / total;
        printf("%d: %e\n", i, radio);
    }
    delete[] probabilities;
}