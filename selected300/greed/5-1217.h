#include "..\head.h"

int minCostToMoveChips(vector<int>& chips) {
    int odd = 0;
    int even = 0;
    for (auto & elem : chips) {
        if (elem % 2 == 1)
            even++
        else 
            odd++;
    }
    return min(odd, even);
}