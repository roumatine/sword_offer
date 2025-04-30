#include "..\..\head.h"

int thirdMax(vector<int> &nums) {
    long long firstNum = LONG_MIN;
    long long secondNum = LONG_MIN;
    long long thirdNum = LONG_MIN;
    for (auto &a : nums) {
        if (firstNum < a) {
            thirdNum = secondNum;
            secondNum = firstNum;
            firstNum = 0;
        } else if (firstNum > a && secondNum < a) {
            thirdNum = secondNum;
            secondNum = a;
        }
        if (secondNum > a && thirdNum < a) {
            thirdNum = a;
        }
        
    }
    if (thirdNum == LONG_MIN) {
        return firstNum;
    } else {
        return thirdNum;
    }
}