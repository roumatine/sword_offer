#include "..\..\head.h"

bool isOneBitCharacter(vector<int> &bits) {
    if (bits[bits.size() - 1] == 1)
        return false;
    int low = 0;
    int high = bits.size();
    while (low < high) {
        if (bits[low] == 1) {
            low += 2;
        } else if (bits[low] == 0) {
            if (low == high - 1)
                break;
            low++;
        }
    }
    if (low == high - 1) {
        return true;
    } else {
        return false;
    }
}