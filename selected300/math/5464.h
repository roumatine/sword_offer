#include "..\..\head.h"

int numWaterBottles(int numBottles, int numExchange) {
    if (numExchange > numBottles)
        return numBottles;
    if (numExchange == numBottles)
        return numBottles + 1;
    int sum = numBottles;
    if (numBottles % (numExchange - 1) == 0)
        sum += -1 + numBottles / (numExchange - 1);
    else 
        sum += numBottles / (numExchange - 1);
    return sum;
    
}