#include "..\..\head.h"

class Solution {
public:
    bool divisorGame(int n) {
        if (n == 1)
            return false;
        return !divisorGame(n - 1);
    }
};